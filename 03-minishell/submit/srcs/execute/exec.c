/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:40:48 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 19:00:35 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** cl == cmd_list
*/

int	non_builtin_exec(t_cmd *cl, char *argv[], char **envp, int fds[])
{
	int		status;
	int		i;
	pid_t	pid;

	i = 0;
	argv[0] = cl->path;
	while (cl->cmdline[++i].cmd != NULL && cl->cmdline[i].redir_flag == 0)
		argv[i] = cl->cmdline[i].cmd;
	argv[i] = NULL;
	pid = fork();
	if (pid < -1)
		return (-1);
	if (pid == 0)
	{
		if (cl->pipe_flag == 1 && cl->right_flag == 0)
			dup2(fds[1], 1);
		if (execve(cl->path, argv, envp) == -1)
			return (-1);
	}
	else if (pid != 0)
	{
		waitpid(pid, &status, 0);
		g_exit_status = status >> 8;
	}
	return (1);
}

int	compare_env_path(t_cmd *cmd_list, t_nbf *nbf, t_arg st_arg, int fds[])
{
	int	i;

	i = -1;
	nbf->env_path = get_env_value("PATH", st_arg.envp);
	nbf->paths = ft_split(nbf->env_path, ':');
	if ((nbf->env_path == NULL) || (nbf->paths == NULL))
		return (-1);
	while (nbf->paths[++i] != NULL)
	{
		cmd_list->path = strjoin_path(nbf->paths[i], cmd_list->cmdline[0].cmd);
		if (cmd_list->path == 0)
			return (-1);
		if (cmd_list->cmdline[0].cmd[0] != '\0'
			&& stat(cmd_list->path, nbf->buf) == 0)
		{
			if (non_builtin_exec(cmd_list, st_arg.argv, st_arg.envp, fds) == -1)
				return (-1);
			free(cmd_list->path);
			return (1);
		}
		free(cmd_list->path);
	}
	return (0);
}

int	non_builtin(t_cmd *cmd_list, t_arg st_arg, int fds[])
{
	t_nbf	nbf;

	init_nbf(&nbf);
	nbf.buf = (struct stat *)malloc(sizeof(struct stat));
	if (nbf.buf == NULL)
		return (-1);
	if (cmd_list->cmdline[0].cmd[0] != '\0'
		&& stat(cmd_list->cmdline[0].cmd, nbf.buf) == 0)
	{
		cmd_list->path = cmd_list->cmdline[0].cmd;
		nbf.flag = non_builtin_exec(cmd_list, st_arg.argv, st_arg.envp, fds);
		if (nbf.flag == -1)
			return (free_nbf(&nbf));
	}
	else
	{
		nbf.flag = compare_env_path(cmd_list, &nbf, st_arg, fds);
		if (nbf.flag == -1)
			return (free_nbf(&nbf));
	}
	free_nbf(&nbf);
	if (nbf.flag == 1 || cmd_list->cmdline[0].redir_flag == 1)
		return (1);
	cmd_list->err_manage.errcode = 1;
	return (-1);
}

int	exec_function(t_cmd *cmd_list, char *argv[], char **envp[], int fds[])
{
	int		fd;
	t_arg	st_arg;

	st_arg.argv = argv;
	st_arg.envp = *envp;
	fd = check_redirect(cmd_list, fds);
	if (fd == -1)
		return (-1);
	if (ft_strncmp("pwd", cmd_list->cmdline[0].cmd, 4) == 0)
		return (ft_pwd(fd));
	else if (ft_strncmp("cd", cmd_list->cmdline[0].cmd, 3) == 0)
		return (ft_cd(cmd_list));
	else if (ft_strncmp("exit", cmd_list->cmdline[0].cmd, 5) == 0)
		return (ft_exit(cmd_list));
	else if (ft_strncmp("env", cmd_list->cmdline[0].cmd, 4) == 0)
		return (ft_env(cmd_list, *envp, fd));
	else if (ft_strncmp("export", cmd_list->cmdline[0].cmd, 7) == 0)
		return (ft_export(cmd_list, envp, fd));
	else if (ft_strncmp("echo", cmd_list->cmdline[0].cmd, 5) == 0)
		return (ft_echo(cmd_list, fd));
	else if (ft_strncmp("unset", cmd_list->cmdline[0].cmd, 6) == 0)
		return (ft_unset(cmd_list, *envp));
	else if (non_builtin(cmd_list, st_arg, fds) == -1)
		return (-1);
	return (0);
}

int	exec(t_cmd *cmd_list, char *argv[], char **envp[])
{
	pid_t	pid;
	int		fds[2];
	int		tmp;

	pipe(fds);
	tmp = exec_function(cmd_list, argv, envp, fds);
	if (tmp == -1)
		print_errstr(cmd_list);
	else if (tmp == 1)
		g_exit_status = 0;
	dup2(100, STDIN);
	dup2(101, STDOUT);
	if (cmd_list->pipe_flag == 1)
	{
		pid = fork();
		if (pid < 0)
			return (-1);
	}
	else
		return (g_exit_status);
	if (pid == 0)
		exec_child(cmd_list, argv, envp, fds);
	else
		return (exec_parents(pid, fds));
	return (0);
}
