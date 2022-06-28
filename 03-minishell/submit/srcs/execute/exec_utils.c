/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:40:22 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 19:17:51 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_nbf(t_nbf *nbf)
{
	nbf->buf = NULL;
	nbf->env_path = NULL;
	nbf->paths = NULL;
	nbf->flag = 0;
}

int	free_nbf(t_nbf *nbf)
{
	int	i;

	i = -1;
	if (nbf->buf != NULL)
		free(nbf->buf);
	if (nbf->paths != NULL)
	{
		while (nbf->paths[++i] != NULL)
			free(nbf->paths[i]);
		free(nbf->paths);
	}
	return (-1);
}

int	check_redirect(t_cmd *cmd_list, int fds[])
{
	int	fd;
	int	tmp;
	int	right_flag;

	right_flag = 0;
	tmp = redir_err_chk(cmd_list);
	right_flag = redirect_check(cmd_list, &fds, -1);
	if (tmp == -1 || right_flag == -1)
		return (-1);
	if (cmd_list->pipe_flag == 1 && right_flag == 0)
		fd = fds[1];
	else
		fd = 1;
	cmd_list->right_flag = right_flag;
	return (fd);
}

void	exec_child(t_cmd *cmd_list, char *argv[], char **envp[], int fds[])
{
	dup2(fds[0], STDIN);
	close(fds[0]);
	close(fds[1]);
	g_exit_status = exec(cmd_list->next, argv, envp);
	exit(g_exit_status);
}

int	exec_parents(int pid, int fds[])
{
	int	status;

	close(fds[1]);
	close(fds[0]);
	waitpid(pid, &status, 0);
	g_exit_status = status >> 8;
	return (g_exit_status);
}
