/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:31 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 20:02:40 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// 종료코드
// ls 옵션을 잘못 사용한 경우
// export 첫 번째 인자와 = 을 띄어 쓴 경우
// export 인자에 숫자가 포함된 경우
// 2번과 3번을 동시에 하는 경우
// exit 정수 인자가 여러 개인 경우
// 환경변수 목록에 없는 변수를 인자로 넣은 경우
// exit 에 정수가 아닌 인자를 넘긴 경우

void	error_write(char *error_str, char *err_cmdline, char *err_cmdline2)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (err_cmdline == 0 || error_str == 0)
		return ;
	while (error_str[++i])
	{
		j = -1;
		// printf와 같이 가변인자 읽는 기능 구현
		if (error_str[i] == '%' && error_str[i + 1] == 's' && err_cmdline != 0)
		{
			while (err_cmdline[++j])
				write(2, &err_cmdline[j], 1);
			err_cmdline = err_cmdline2;
			i++;
		}
		else
			write(2, &error_str[i], 1);
	}
}

void	ft_print_unset_err(t_cmd *cmd_list)
{
	int i;

	i = 1;
	while (cmd_list->cmdline[i].cmd && cmd_list->cmdline[i].redir_flag == 0)
	{
		if (ft_valid_key(cmd_list->cmdline[i].cmd) == 0)
			error_write("minishell: %s: `%s': not a valid identifier\n",
						cmd_list->cmdline[0].cmd, cmd_list->cmdline[i].cmd);
		i++;
	}
}

void	ft_print_export_err(t_cmd *cmd_list)
{
	int	i;

	i = 1;
	while (cmd_list->cmdline[i].cmd && cmd_list->cmdline[i].redir_flag == 0)
	{
		if (isvalid_export(cmd_list->cmdline[i].cmd) == 0)
			error_write("minishell: %s: `%s': not a valid identifier\n",
						cmd_list->cmdline[0].cmd, cmd_list->cmdline[i].cmd);
		i++;
	}
}

void	print_errstr2(t_cmd *cmd_list)
{
	if (cmd_list->err_manage.errcode == 5 || cmd_list->err_manage.errcode == 6)
		g_exit_status = 1;
	else if (cmd_list->err_manage.errcode == 7
										|| cmd_list->err_manage.errcode == 8)
		g_exit_status = 255;
	if (cmd_list->err_manage.errcode == 5)
		ft_print_export_err(cmd_list);
	else if (cmd_list->err_manage.errcode == 6)
		ft_print_unset_err(cmd_list);
	else if (cmd_list->err_manage.errcode == 7)
	{
		if (cmd_list->err_manage.errtoken)
			error_write("minishell: syntax error near unexpected token `%s'\n", \
						cmd_list->err_manage.errtoken, 0);
		else
			error_write("minishell: syntax error near unexpected token `%s\'\n", \
					cmd_list->cmdline[cmd_list->err_manage.errindex].cmd, 0);
	}
	else if (cmd_list->err_manage.errcode == 8)
	{
		error_write("minishell: syntax error near unexpected token `newline\'\n", \
					cmd_list->cmdline[cmd_list->err_manage.errindex].cmd, 0);
	}
}

void	print_errstr(t_cmd *cmd_list)
{
	if (cmd_list->err_manage.errcode == 1)
	{
		error_write("minishell: %s: command not found\n", \
					cmd_list->cmdline[0].cmd, 0);
		g_exit_status = 127;
	}
	else if (cmd_list->err_manage.errcode == 2)
	{
		error_write("minishell: %s: too many arguments\n", \
					cmd_list->cmdline[0].cmd, 0);
		g_exit_status = 1;
	}
	else if (cmd_list->err_manage.errcode == 3)
	{
		error_write("minishell: %s: No such file or directory\n", \
					cmd_list->cmdline[cmd_list->err_manage.errindex].cmd, 0);
		g_exit_status = 1;
		if (ft_strncmp("env", cmd_list->cmdline[0].cmd, 4) == 0)
			g_exit_status = 127;
	}
	print_errstr2(cmd_list);
	// errocode == 4 exit 함수 잘못사용할떄 입력
	print_errstr3(cmd_list);
}
