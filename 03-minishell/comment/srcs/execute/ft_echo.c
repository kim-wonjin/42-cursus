/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:41:08 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 19:48:52 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// -n -nnnn -n-n-n 등 모두 -n으로 처리
int	n_opt_chk(char *cmd)
{
	int	i;

	i = 1;
	if (ft_strncmp("-n", cmd, 2) != 0)
		return (0);
	while (cmd[++i])
	{
		if (cmd[i] != 'n')
			return (0);
	}
	return (1);
}

int	ft_echo(t_cmd *cmd_list, int fd)
{
	int	flg;
	int	i;
	int	cnt;

	i = 1;
	flg = 0;
	cnt = 0;
	while (n_opt_chk(cmd_list->cmdline[i].cmd))
	{
		flg = 1;
		i++;
	}
	while (cmd_list->cmdline[i].cmd && cmd_list->cmdline[i].redir_flag == 0)
	{
		// cmd 중간중간 spacebar 처리
		if (cnt != 0)
			write(fd, " ", 1);
		ft_putstr_fd(cmd_list->cmdline[i].cmd, fd);
		i++;
		cnt++;
	}
	if (flg == 0)
		write(fd, "\n", 1);
	return (1);
}
