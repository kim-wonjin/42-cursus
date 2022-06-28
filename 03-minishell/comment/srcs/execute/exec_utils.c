/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:40:22 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 20:07:28 by hyseo            ###   ########.fr       */
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
	int	right_flag;

	right_flag = 0;
	// << 때문에 &fds 로 보낸다. 포인터로 그 주소값에 들어있는 값을 바꿔야 하기 때문에
	if ((redir_err_chk(cmd_list) == -1) ||
			((right_flag = redirect_check(cmd_list, &fds)) == -1))
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
	//stdin = 0 / stdout = 1 / stderr = 3
	// pt자료 참고
	dup2(fds[0], STDIN);
	close(fds[0]);
	close(fds[1]);
	// 자식프로세스 cmd 실행
	g_exit_status = exec(cmd_list->next, argv, envp);
	exit(g_exit_status);
}

int	exec_parents(int pid, int fds[])
{
	int	status;

	close(fds[1]);
	close(fds[0]);
	// pid -> 자식 프로세스가 종료 될때까지 기다린다.
	// waitpid(pid_t pid, int *status, int options)
	waitpid(pid, &status, 0);
	// WIFEXITED(statloc) 매크로가 true를 반환
	// 하위 8비트를 참조하여 자식 프로세스가 exit, _exit, _Exit에 넘겨준 인자값을 얻을 수 있음, WEXITSTATUS(statloc)
	g_exit_status = status >> 8;
	return (g_exit_status);
}
