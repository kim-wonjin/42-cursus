/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:54 by sshin             #+#    #+#             */
/*   Updated: 2022/06/27 00:27:20 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status = 0;

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	t_cmd	*cmd_list;
	char	**cpenv;

	dup2(STDIN, 100); // 파일 식별자 변경 가능
	dup2(STDOUT, 101);
	argc = 1;  // 경고 출력 방지용 임의사용
	cpenv = copy_envp(envp); // envp == 환경변수 목록
	// 키=항목
	// 키=항목
	// 키=항목
	// NULL
	set_signal(); // SIGINT, SIGQUIT에 대한 handler 설정
	while ((line = readline("minishell $ "))) // get next line
	{
		if (*line != '\0' && !check_whitespace(line)) // skip white spc
		{
			add_history(line);
			// readline 함수의 기본 동작 중에 사용자가 입력했던 문자열을 다시 얻게 해주는 함수이다.
			// add_history의 인자인 line으로 기재한 문자열은 위와 아래 방향키를 통해서
			// readline 함수 실행 도중에 다시 불러올 수 있다.
			parse(&cmd_list, line, cpenv);
			// 문제 없을 시 exec에서 0 리턴
			g_exit_status = exec(cmd_list, argv, &cpenv);
			// 파이프가 없을 시 exec에서 -1 리턴, 한 번 실행 후 프로세스 종료
			free_list(cmd_list);
			// 연결리스트의 모든 동적할당 해제
		}
		free(line);
	}
	return (0);
}
