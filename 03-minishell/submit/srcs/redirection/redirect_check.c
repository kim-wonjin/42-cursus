/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:22 by sshin             #+#    #+#             */
/*   Updated: 2022/02/14 10:35:12 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_fd_error(t_cmd *cmd_list, int errorcode, int error_index, int fd)
{
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
	cmd_list->redirect_filename[first] = cmd_list->cmdline[i].cmd;
	cmd_list->redirect_filename[second] = cmd_list->cmdline[i + 1].cmd;
}

int	next_value_end_and_put_fname_data(t_cmd *cmd_list,
							int i, int file_name_index, int *last_index)
{
	if (cmd_list->cmdline[i + 1].cmd == 0)
	{
		cmd_list->err_manage.errcode = 8;
		return (-1);
	}
	else if (cmd_list->cmdline[i + 1].redir_flag == 1)
	{
		cmd_list->err_manage.errcode = 7;
		cmd_list->err_manage.errindex = i + 1;
		return (-1);
	}
	save_filename(cmd_list, i, file_name_index, file_name_index + 1);
	if (file_name_index == 0)
		last_index[0] = i + 1;
	if (file_name_index == 2)
		last_index[1] = i + 1;
	return (0);
}

int	open_test_save_filename(t_cmd *cmd_list, int i, int *last_index, char *flag)
{
	int	fd;

	fd = 0;
	if (ft_strncmp("left_redirect", flag, 14) == 0
		&& next_value_end_and_put_fname_data(cmd_list, i, 0, last_index) == -1)
		return (-1);
	else if (ft_strncmp("right_redirect", flag, 15) == 0
		&& next_value_end_and_put_fname_data(cmd_list, i, 2, last_index) == -1)
		return (-1);
	if (ft_strncmp("<", cmd_list->cmdline[i].cmd, 2) == 0)
		fd = open(cmd_list->cmdline[i + 1].cmd, O_WRONLY | O_APPEND, 0744);
	else if (ft_strncmp(">", cmd_list->cmdline[i].cmd, 2) == 0)
		fd = open(cmd_list->cmdline[i + 1].cmd,
				O_WRONLY | O_CREAT | O_TRUNC, 0744);
	else if (ft_strncmp(">>", cmd_list->cmdline[i].cmd, 3) == 0)
		fd = open(cmd_list->cmdline[i + 1].cmd,
				O_WRONLY | O_CREAT | O_APPEND, 0744);
	else if (ft_strncmp("<<", cmd_list->cmdline[i].cmd, 3) == 0)
		return (0);
	if (check_fd_error(cmd_list, 3, i + 1, fd) == -1)
		return (-1);
	close(fd);
	return (0);
}

int	redirect_check(t_cmd *cmd_list, int *fds[], int i)
{
	int	last_index[2];

	while (++i < 4)
		cmd_list->redirect_filename[i] = 0;
	i = -1;
	while (cmd_list->cmdline[++i].cmd)
	{
		if (cmd_list->cmdline[i].redir_flag == 0)
			;
		else if ((ft_strncmp("<", cmd_list->cmdline[i].cmd, 2) == 0
				|| ft_strncmp("<<", cmd_list->cmdline[i].cmd, 3) == 0)
			&& (open_test_save_filename(cmd_list, i, last_index, \
				"left_redirect") == -1))
			return (-1);
		else if ((ft_strncmp(">", cmd_list->cmdline[i].cmd, 2) == 0
				|| ft_strncmp(">>", cmd_list->cmdline[i].cmd, 3) == 0)
			&& (open_test_save_filename(cmd_list, i, last_index, \
				"right_redirect") == -1))
			return (-1);
	}
	if ((cmd_list->redirect_filename[0]
			|| cmd_list->redirect_filename[2]))
		return (redirect(cmd_list, last_index, fds));
	return (0);
}
