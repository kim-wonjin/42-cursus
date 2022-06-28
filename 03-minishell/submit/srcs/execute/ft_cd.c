/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:41:02 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 19:36:18 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	mv_home(char **pst_buffer)
{
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

	tmp = cmd_list->cmdline[1].cmd;
	cmd_list->cmdline[1].cmd = ft_strjoin(getenv("HOME"),
			&cmd_list->cmdline[1].cmd[1]);
	free(tmp);
}

int	ft_cd(t_cmd *cmd_list)
{
	int		i;
	char	*pst_buffer;

	i = 0;
	if (cmd_list->cmdline[1].cmd == 0 || cmd_list->cmdline[1].redir_flag == 1)
		return (mv_home(0));
	pst_buffer = getcwd(0, 0);
	if (cmd_list->cmdline[1].cmd[0] == '~')
	{
		if (cmd_list->cmdline[1].cmd[1] == '/')
			make_path(cmd_list);
		else if (cmd_list->cmdline[1].cmd[1] == 0)
			return (mv_home(&pst_buffer));
	}
	if (chdir(cmd_list->cmdline[1].cmd) == -1)
	{
		chdir(pst_buffer);
		free(pst_buffer);
		return (put_err_data(cmd_list, 3, 1));
	}
	free(pst_buffer);
	return (1);
}
