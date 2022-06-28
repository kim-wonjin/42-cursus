/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:41:02 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 19:40:06 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	mv_home(char **pst_buffer)
{
	//int chdir( const char *dirname );
	//dirname : 변경할 디렉토리의 경로
	//반환값 : 정상 일 때 0, 에러 시 -1
	// getenv() 함수는 varname에 해당한 항목에 대한 환경 변수의 리스트를 검색합니다.
	chdir(getenv("HOME"));
	if (pst_buffer != 0)
		free(*pst_buffer);
	return (1);
}

int	put_err_data(t_cmd *cmd_list, int errcode, int errindex)
{
	cmd_list->err_manage.errcode = errcode;
	cmd_list->err_manage.errindex = errindex;
	return (-1);
}

void	make_path(t_cmd *cmd_list)
{
	char	*tmp;

	// tmp 는 왜 생성???? 어디다가 사용???
	tmp = cmd_list->cmdline[1].cmd;
	// HOME = /Users/$(USER) 뒤에 /와 뒤 패쓰를 strjoin
	cmd_list->cmdline[1].cmd = ft_strjoin(getenv("HOME"),
								&cmd_list->cmdline[1].cmd[1]);
	free(tmp);
}

int	ft_cd(t_cmd *cmd_list)
{
	int		i;
	char	*pst_buffer;

	i = 0;
	// cmdline.cmd[0] 는 cd
	// redir == 1 인 경우
	// cd > t.txt 플래그가 있는 경우 우선 무시하고 root로 이동
	if (cmd_list->cmdline[1].cmd == 0 || cmd_list->cmdline[1].redir_flag == 1)
		return (mv_home(0));
	// return 1 일 경우 tmp=1 -> g_exit_status = 0 
	
	// 현재 디렉토리 정보 저장  == pwd
	// getcwd() 현재 작업 full path명 반환 0, 0 인자 보낼 시 자동으로 메모리 할당 하기 때문에
	// free 필요
	pst_buffer = getcwd(0, 0);
	if (cmd_list->cmdline[1].cmd[0] == '~')
	{
		if (cmd_list->cmdline[1].cmd[1] == '/')
			make_path(cmd_list);
		else if (cmd_list->cmdline[1].cmd[1] == 0)
			return (mv_home(&pst_buffer));
	}
	// 없는 디렉토리인 경우 현재 디렉토리에 머무르기
	if (chdir(cmd_list->cmdline[1].cmd) == -1)
	{
		chdir(pst_buffer);
		free(pst_buffer);
		return (put_err_data(cmd_list, 3, 1));
	}
	free(pst_buffer);
	return (1);
}
