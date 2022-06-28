/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:41:19 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 19:45:33 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_exit(t_cmd *cmd_list)
{
	long long	result;
	int			err_flag;

	err_flag = 0;
	result = ft_atoi(cmd_list->cmdline[1].cmd, &err_flag);
	if (err_flag == 1)
	{
		cmd_list->err_manage.errcode = 4;
		cmd_list->err_manage.errindex = 1;
		print_errstr(cmd_list);
		// https://softwareengineering.stackexchange.com/questions/314563/where-did-exit-1-come-from
		//- exit 에 양수가 아닌 인자를 넘긴 경우
    	//	알수 없는 오류일 경우 
		exit(-1);
	}
	// 에러코드는 255까지 있기 때문에
	exit(result % 256);
}

int	check_digit(t_cmd *cmd_list)
{
	int	i;

	i = -1;
	// -는 무시 -> 양수로 처리해야 하기 때문에
	if (cmd_list->cmdline[1].cmd[0] == '-')
		i++;
	while (cmd_list->cmdline[1].cmd[++i] != '\0')
	{
		// isdigit return = 0 -> 숫자가 아니다.
		if (ft_isdigit(cmd_list->cmdline[1].cmd[i]) == 0)
		{
			if (cmd_list->exit_flag == 1)
			{
				cmd_list->err_manage.errcode = 4;
				// errindex 는 에러가 일어난 cmd 위치
				// error_management 에서 error_write("minishell: syntax error near unexpected token `newline\'\n"
				//, cmd_list->cmdline[cmd_list->err_manage.errindex].cmd, 0);
				// 이런 식으로 사용 됨.
				// 에서 cmd 인자를 넘기는 대신 index로 구분해서 오류 cmd 검색
				cmd_list->err_manage.errindex = 1;
				print_errstr(cmd_list);
				exit(-1);
			}
			else
			{
				cmd_list->err_manage.errcode = 4;
				cmd_list->err_manage.errindex = 1;
				return (0);
			}
		}
	}
	return (1);
}

int	ft_exit(t_cmd *cmd_list)
{
	if (cmd_list->exit_flag == 1)
		printf("exit\n");
	// 사용자가 에러코드를 입력했는지 확인 (숫자인지)
	if (cmd_list->cmdline[1].cmd != NULL)
	{
		if (check_digit(cmd_list) == 0)
			return (-1);
		if (cmd_list->cmdline[2].cmd != NULL)
		{
			cmd_list->err_manage.errcode = 2;
			return (-1);
		}
		// exit_flag get_new_node 에서 세팅
		// | 등 아무것도 없고 바로 종료 가능 할때
		if (cmd_list->exit_flag == 1)
			exec_exit(cmd_list);
	}
	// 단순히 exit 만 입력했을 시에는 에러 코드 0으로 종료
	else if (cmd_list->exit_flag == 1)
		exit(0);
	return (1);
}
