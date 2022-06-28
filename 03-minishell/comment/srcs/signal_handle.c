/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:59 by sshin             #+#    #+#             */
/*   Updated: 2022/06/27 05:10:15 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <signal.h>

// SIGINT == ctrl+C
// 실행을 중지하고 프로세스 종료
// 프롬프트를 다시 띄우게 된다.
void	funtion_sigint(pid_t pid)
{
	if (pid == -1) // waitpid() 오류  - 자식 프로세스가 없을 경우
	{
		rl_on_new_line();
		// readline 디렉토리 내에서 Update 관련 함수들에게 커서가 개행 문자를 통해 다음 줄로
		// 이동했음을 알려줄 때 이용되는 함수이다. 알림 용도의 함수이므로 직접적으로 해당 함수가
		// 개행문자를 수정해주지는 않는다. 따라서 해당 함수는 개행문자 출력 이후에 이용된다.
		rl_redisplay();
		// 사용자가 입력하여 유지중인 rl_line_buffer의 값을 프롬프트와 함께 출력해준다.
		// 이때 프롬프트 값은 readline 함수에 prompt로 준 문자열로 이용된다.
		ft_putstr_fd("  \n", STDOUT);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
		ft_putstr_fd("\n", STDOUT);
}

// SIGQUIT == ctrl+\
// 실행을 중지하고 프로세스를 종료시킨 뒤 코어 덤프
// (코어덤프란 프로그램이 비정상적으로 종료되었을 때 작성중이던
// 메모리의 상태를 기록한 파일이다.)
void	funtion_sigquit(pid_t pid)
{
	if (pid == -1) // waitpid() 오류 // do nothing
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("  \b\b", STDOUT);
	}
	else
		ft_putstr_fd("Quit: 3\n", STDOUT);
}

void	handle_signal(int signo)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	// waitpid:
	// 정상적으로 자식 프로세스의 상태를 획득하고 자원을 수거하고 반환한다.
	// 특정 pid를 가진 자식 프로세스의 종료를 기다렸다가 수거한다.
	// pid로 -1이라는 값을 주게 되면, wait과 동일하게 동작하여 임의의 프로세스를 수거한다.
	// WNOHANG: 자식 프로세스의 종료를 기다리지 않고 즉시 자식 프로세스의 status에 대해 반환
	if (signo == SIGINT)
		funtion_sigint(pid);
	else if (signo == SIGQUIT)
		funtion_sigquit(pid);
}

void	set_signal(void)
{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
}
