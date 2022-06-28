/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:22 by sshin             #+#    #+#             */
/*   Updated: 2022/06/28 07:07:07 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_fd_error(t_cmd *cmd_list, int errorcode, int error_index, int fd)
{
	//errocode 3 -> 	error_write("minishell: %s: No such file or directory\n",
	if (fd <= 0)
	{
		cmd_list->err_manage.errcode = errorcode;
		cmd_list->err_manage.errindex = error_index;
		return (-1);
	}
	return (0);
}

void	save_filename(t_cmd *cmd_list, int i, int first, int second)
{
	//file_name_index = first 는 0 또는 2  second 는 1 또는 3
	cmd_list->redirect_filename[first] = cmd_list->cmdline[i].cmd;
	cmd_list->redirect_filename[second] = cmd_list->cmdline[i + 1].cmd;
}

int	next_value_end_and_put_fname_data(t_cmd *cmd_list,
							int i, int file_name_index, int *last_index)
{
	// 리다이렉트 뒤에 아무것도 없을 경우
	if (cmd_list->cmdline[i + 1].cmd == 0)
	{
		cmd_list->err_manage.errcode = 8;
		return (-1);
	}
	// 플래그가 동일하게 또 들어갔을 경우 >> >>  >>>> 는 예외처리했지만 중간에 띄어쓰기가 있는것은 처리 안했기 때문에
	else if (cmd_list->cmdline[i + 1].redir_flag == 1)
	{
		cmd_list->err_manage.errcode = 7;
		cmd_list->err_manage.errindex = i + 1;
		return (-1);
	}
	// 파일 이름 저장
	//index 0 : left redirect char (<, <<);
	//index 1 : left redirect filename;
	//index 2 : righ redirect char (>, >>);
	//index 3 : righ redirect filename;
	// cmdlist 의 cmd 인덱스인 i + 1 를 해서 라스트 인덱스에 저장 << >> 에 따라서

	//check_fd_error(t_cmd *cmd_list, int errorcode, int error_index, int fd)
	// 에서 error_index 로 last_index가 넘어간다.
	save_filename(cmd_list, i, file_name_index, file_name_index + 1);
	// last_index는 redirect.c 에서 사용한다.
	// 오른쪽은 파일명으로 새로 생성되는 것이기 때문에 last_index[1] 빈값이 오류 인덱스로 넘어간다.
	if (file_name_index == 0)
		last_index[0] = i + 1;
	if (file_name_index == 2)
		last_index[1] = i + 1;
	return (0);
}

// 파일 잘열리는지 확인하기.
int	open_test_save_filename(t_cmd *cmd_list, int i, int *last_index, char *flag)
{
	int	fd;

	fd = 0;
	// 리다이렉트 확인 및 초기화 작업 0 과 2는 file_name_index -> 왼쪽인지 오른쪽인지 확인하기 위해
	if (ft_strncmp("left_redirect", flag, 14) == 0
	&& next_value_end_and_put_fname_data(cmd_list, i, 0, last_index) == -1)
		return (-1);
	else if (ft_strncmp("right_redirect", flag, 15) == 0
	&& next_value_end_and_put_fname_data(cmd_list, i, 2, last_index) == -1)
		return (-1);
	// < 는 파일명을 읽어서 명령어 실행하는 기능  ex  cat < file.txt
	if (ft_strncmp("<", cmd_list->cmdline[i].cmd, 2) == 0)
		fd = open(cmd_list->cmdline[i + 1].cmd, O_WRONLY | O_APPEND, 0744);
	// 수정,읽기 모두 가능, 없으면 새로 만들기, 만약있으면 지우고 새로 생성
	else if (ft_strncmp(">", cmd_list->cmdline[i].cmd, 2) == 0)
		fd = open(cmd_list->cmdline[i + 1].cmd,
						O_WRONLY | O_CREAT | O_TRUNC, 0744);
	// 수정,읽기 모두 가능, 없으면 새로 만들기, 만약 있으면 이어쓰기
	else if (ft_strncmp(">>", cmd_list->cmdline[i].cmd, 3) == 0)
		fd = open(cmd_list->cmdline[i + 1].cmd,
						O_WRONLY | O_CREAT | O_APPEND, 0744);
	// << 인 경우에는 파일을 읽는 것이 아니기 때문에 정상종료 0 리턴 
	// fd가 없기 때문에 아래 check_fd_error 로 내려가지 않게
	// 	# cat <<EOF > /etc/resolv.conf
	// > nameserver 168.126.63.1
	// > nameserver 168.126.63.2
	// > EOF
	// EOF 를 사용하여 파일을 만들 때 주로 사용 된다.
	else if (ft_strncmp("<<", cmd_list->cmdline[i].cmd, 3) == 0)
		return (0);
	if (check_fd_error(cmd_list, 3, i + 1, fd) == -1)
		return (-1);
	close(fd);
	return (0);
}

int	redirect_check(t_cmd *cmd_list, int *fds[])
{
	int	i;
	int	last_index[2];

	i = -1;
	// filename 초기화
	while (++i < 4)
		cmd_list->redirect_filename[i] = 0;
	i = -1;
	while (cmd_list->cmdline[++i].cmd)
	{
		if (cmd_list->cmdline[i].redir_flag == 0)
			;
		// < 혹은 << 인경우 파일 제대로 열리는지 확인
		// 딱 < 하나만 있어야 하기 때문에 바이트를 1 더크게 읽는다.
		else if ((ft_strncmp("<", cmd_list->cmdline[i].cmd, 2) == 0
	|| ft_strncmp("<<", cmd_list->cmdline[i].cmd, 3) == 0) &&
	(open_test_save_filename(cmd_list, i, last_index, "left_redirect") == -1))
			return (-1);
		else if ((ft_strncmp(">", cmd_list->cmdline[i].cmd, 2) == 0
	|| ft_strncmp(">>", cmd_list->cmdline[i].cmd, 3) == 0) &&
	(open_test_save_filename(cmd_list, i, last_index, "right_redirect") == -1))
			return (-1);
	}
	// save_filename 에서 저장
	// << 혹은 >> 이 들어있을 경우 1 -> redirect 실행
	if ((cmd_list->redirect_filename[0]
						|| cmd_list->redirect_filename[2]) ? 1 : 0)
		return (redirect(cmd_list, last_index, fds));
	else
		return (0);
}
