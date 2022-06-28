/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:40:48 by sshin             #+#    #+#             */
/*   Updated: 2022/06/28 13:54:24 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	non_builtin_exec(t_cmd *cmd_list, char *argv[], char **envp,
					int fds[])
{
	int		status;
	pid_t	pid;
	int		i;

	i = 0;
	argv[0] = cmd_list->path;
	while (cmd_list->cmdline[++i].cmd != NULL
			&& cmd_list->cmdline[i].redir_flag == 0)
		argv[i] = cmd_list->cmdline[i].cmd;
	argv[i] = NULL;
	if ((pid = fork()) < -1)
		return (-1);
	if (pid == 0)
	{
		// 환경변수를 자식 프로세스에서도 사용할 수 있도록 dup2()
		if (cmd_list->pipe_flag == 1 && cmd_list->right_flag == 0)
			dup2(fds[1], 1);
		// execve 를 이용하여 실행
		// https://www.it-note.kr/157
		if (execve(cmd_list->path, argv, envp) == -1)
			return (-1);
	}
	else if (pid != 0)
	{
		waitpid(pid, &status, 0);
		g_exit_status = status >> 8;
	}
	return (1);
}

int	compare_env_path(t_cmd *cmd_list, t_nbf *nbf, t_arg st_arg,
					int fds[])
{
	int	i;

	i = -1;
	if (((nbf->env_path = get_env_value("PATH", st_arg.envp)) == NULL) ||
			((nbf->paths = ft_split(nbf->env_path, ':')) == NULL))
		return (-1);
	while (nbf->paths[++i] != NULL)
	{
		// join 과정에서 구분자 / 를 넣어준다.
		if ((cmd_list->path =
				strjoin_path(nbf->paths[i], cmd_list->cmdline[0].cmd)) == 0)
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
	int		i;

	i = -1;
	// non_builtin 을 위한 구조체 초기화
	init_nbf(&nbf);
	if (!(nbf.buf = (struct stat*)malloc(sizeof(struct stat))))
		return (-1);
	//stat() 함수를 이용하면 파일의 상태를 알아올수 있다. 
	// 첫번째 인자로 주어진 file_name 의 상태를 얻어와서 두번째 인자인 buf 에 채워 넣는다.
	// cmd 에 경로를 입력 했을 경우
	// 불러오기 성공하면 0
	if (cmd_list->cmdline[0].cmd[0] != '\0' &&
			stat(cmd_list->cmdline[0].cmd, nbf.buf) == 0)
	{
		cmd_list->path = cmd_list->cmdline[0].cmd;
		if ((nbf.flag =
			non_builtin_exec(cmd_list, st_arg.argv, st_arg.envp, fds)) == -1)
			return (free_nbf(&nbf));
	}
	else
	{
		// PATH 에 등록되어있는 경로탐색 ls cat 등 명령어만 입력했을 경우
		if ((nbf.flag = compare_env_path(cmd_list, &nbf, st_arg, fds)) == -1)
			return (free_nbf(&nbf));
	}
	free_nbf(&nbf);
	if (nbf.flag == 1 || cmd_list->cmdline[0].redir_flag == 1)
		return (1);
	cmd_list->err_manage.errcode = 1;
	return (-1);
}

int	exec_function(t_cmd *cmd_list, char *argv[], char **envp[],
					int fds[])
{
	int		fd;
	t_arg	st_arg;

	st_arg.argv = argv;
	st_arg.envp = *envp;
	//exec_util.c 잘못된 redirect 체크 / redirect 정보 입력
	if ((fd = check_redirect(cmd_list, fds)) == -1)
		return (-1);
	// 명령어 뒤에 스페이스가 있어야 하기 때문에 글자수 + 1 만큼 검사 한다.
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
	// 그외 명령어 일경우 execve 함수를 사용하여 실행
	else if (non_builtin(cmd_list, st_arg, fds) == -1)
		return (-1);
	return (0);
}

int	exec(t_cmd *cmd_list, char *argv[], char **envp[])
{
	pid_t	pid;
	int		fds[2];
	int		tmp;

	// 파이프 생성
	pipe(fds);
	// cmd 실행
	// tmp 가 -1 이면 문제가 발생한것이기 때문에 err 출력
	// 1이면 프로세스가 정상 작동한 것이 때문에 g_exit_status = 0 
	if ((tmp = exec_function(cmd_list, argv, envp, fds)) == -1)
		print_errstr(cmd_list);
	else if (tmp == 1)
		g_exit_status = 0;
	// minishell readline 받기 위해 초기화
	dup2(101, STDIN);
	dup2(100, STDOUT);
	// parse.c  | 가 있을 경우 자식 프로세스 생성.
	if (cmd_list->pipe_flag == 1)
	{
		// 자식 fork 생성 오류일때
		if ((pid = fork()) < 0)
			return (-1);
	}
	// 자식프로세스 생성 안해도 되는 경우 리턴
	else
		return (g_exit_status);
	// exec_util.c 자식프로세서 생성 -> exec 반복
	if (pid == 0)
		exec_child(cmd_list, argv, envp, fds);
	else
		return (exec_parents(pid, fds));
	return (0);
}
