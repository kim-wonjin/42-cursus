/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:26 by sshin             #+#    #+#             */
/*   Updated: 2022/02/14 10:33:36 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	left_redirect(t_cmd *cmd_list, int *last_index)
{
	int	fd;

	fd = open(cmd_list->redirect_filename[1], O_RDONLY, 0644);
	if (check_fd_error(cmd_list, 3, last_index[0], fd) == -1)
		return (-1);
	dup2(fd, STDIN);
	close(fd);
	return (0);
}

int	left_redirect_double(t_cmd *cmd_list, int **fds)
{
	char	*line;

	line = readline("> ");
	while (ft_strncmp(line, cmd_list->redirect_filename[1], 5))
	{
		ft_putendl_fd(line, (*fds)[1]);
		line = readline("> ");
	}
	close((*fds)[1]);
	dup2((*fds)[0], 0);
	close((*fds)[0]);
	pipe((*fds));
	return (0);
}

int	right_redirect(t_cmd *cmd_list, int *last_index)
{
	int	fd;

	fd = open(cmd_list->redirect_filename[3],
			O_WRONLY | O_CREAT | O_TRUNC, 0744);
	if (check_fd_error(cmd_list, 3, last_index[1], fd) == -1)
		return (-1);
	dup2(fd, STDOUT);
	close(fd);
	return (1);
}

int	right_redirect_double(t_cmd *cmd_list, int *last_index)
{
	int	fd;

	fd = open(cmd_list->redirect_filename[3],
			O_WRONLY | O_CREAT | O_APPEND, 0744);
	if (check_fd_error(cmd_list, 3, last_index[1], fd) == -1)
		return (-1);
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
