/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:26 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 20:02:25 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	left_redirect(t_cmd *cmd_list, int *last_index)
{
	int	fd;

	fd = open(cmd_list->redirect_filename[1], O_RDONLY, 0644);
	// fd == -1 은 파일 불러오기 실패한 경우
	// last_index[0] = i + 1   < 다음에 있는 파일명 오류 인덱스로 넘겨서 확인
	if (check_fd_error(cmd_list, 3, last_index[0], fd) == -1)
		return (-1);
	// fd 를 STDIN 으로 변경 (부모가 해당 파일에서 데이터를 읽어야 하기 때문에)
	dup2(fd, STDIN);
	// close 로 닫지 않으면 기존 fd 도 STDIN 과 동일한 기능을 한다.
	// 파이프는 출구를 닫지 않으면 EOF가 어딘지 모르기 때문에 데이터 유실이 발생할 수 있다.
	close(fd);
	return (0);
}

int	left_redirect_double(t_cmd *cmd_list, int **fds)
{
	char	*line;

	// >>  이어쓰기
	// readline("> ")) 로 계속 읽는 이유는 EOF로 끝나기 전까지 계속 읽어 나가야 하기 때문에. ->  > EOF
	// readline 을 통해 터미널에 출력
	while (ft_strncmp((line = readline("> ")),
					cmd_list->redirect_filename[1], 5))
		ft_putendl_fd(line, (*fds)[1]);
	// - fd[0] : 함수 호출 후 fd[0]에 데이터를 입력 받을 수 있는 파일 디스크립터가 담김(파이프 출구)
	//- fd[1] : 함수 호출 후 데이터를 출력할 수 있는 파일 디스크립터다 담긴다(파이프 입구)
	// 위에서 EOF(구분자) 전까지 *fds[1] (입력) 에 계속 입력이 되었기 때문에 사용 후 종료
	// check_redirect 에서부터 fds 포인터값으로 보낸다 값 자체를 바꿔야 하기 때문에.
	close((*fds)[1]);
	// 표준 입력으로 바꾼다. -> fds[1] 에 담긴 내용들을 STDIN에서 읽어 올수 있게.
	dup2((*fds)[0], 0);
	close((*fds)[0]);
	// 다시 앞에 cmd가 원래되로 fd를 통해 데이터를 주고 받을 수 있게 다시 fd값 생성. 초기화
	// 기존 fds STDIN으로 바뀌고 닫혔기 때문에 새로 pipe를 만들어 주어야 
	// <<EOF 이후 > 리다리렉션도 파이프를 통해 데이터 전송을 할 수 있다.
	pipe((*fds));
	return (0);
}

int	right_redirect(t_cmd *cmd_list, int *last_index)
{
	int	fd;

	fd = open(cmd_list->redirect_filename[3],
						O_WRONLY | O_CREAT | O_TRUNC, 0744);
	// 파일 열리지 않으면 last_index가 리턴된다.
	if (check_fd_error(cmd_list, 3, last_index[1], fd) == -1)
		return (-1);
	// fd로 출력 될 수 있게 dup2
	dup2(fd, STDOUT);
	close(fd);
	return (1);
}

int	right_redirect_double(t_cmd *cmd_list, int *last_index)
{
	int	fd;

	fd = open(cmd_list->redirect_filename[3],
						O_WRONLY | O_CREAT | O_APPEND, 0744);
	// 새로 생긴, 이미 존재 하는 파일명 last_index[1]
	if (check_fd_error(cmd_list, 3, last_index[1], fd) == -1)
		return (-1);
	// fd로 출력 될 수 있게 dup2
	dup2(fd, STDOUT);
	close(fd);
	return (1);
}

int	redirect(t_cmd *cmd_list, int *last_index, int *fds[])
{
	int	error_left;
	int	error_right;

	error_left = 0;
	error_right = 0;
	// filname 에 담겨있는 < << > >> 구분해서 맞는 함수 실행
	if (ft_strncmp("<", cmd_list->redirect_filename[0], 2) == 0)
		error_left = left_redirect(cmd_list, last_index);
	else if (ft_strncmp("<<", cmd_list->redirect_filename[0], 3) == 0)
		error_left = left_redirect_double(cmd_list, fds);
	if (ft_strncmp(">", cmd_list->redirect_filename[2], 2) == 0)
		error_right = right_redirect(cmd_list, last_index);
	else if (ft_strncmp(">>", cmd_list->redirect_filename[2], 3) == 0)
		error_right = right_redirect_double(cmd_list, last_index);
	if (error_left == -1 || error_right == -1)
		return (-1);
	if (error_right == 1)
		return (1);
	return (0);
}
