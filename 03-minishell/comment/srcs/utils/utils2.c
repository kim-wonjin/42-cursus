/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:48 by sshin             #+#    #+#             */
/*   Updated: 2022/02/10 21:00:30 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_errstr3(t_cmd *cmd_list)
{
	if (cmd_list->err_manage.errcode == 4)
	{
		error_write("minishell: %s: %s: numeric argument required\n", \
cmd_list->cmdline[0].cmd, cmd_list->cmdline[cmd_list->err_manage.errindex].cmd);
		g_exit_status = 255;
	}
}

void	str_forward(char *line, int *i)
{
	int j;

	j = 0;
	while (line[(*i) + j])
	{
		line[(*i) + j] = line[(*i) + j + 1];
		j++;
	}
	(*i)--;
}

char	check_quote(char *line)
{
	char	result;
	int		i;

	i = -1;
	result = 0;
	while (line[++i] != '\0')
	{
		if (line[i] == '"' && (result == 0 || result == '"'))
		{
			if (result == '"')
				result = 0;
			else
				result = '"';
			str_forward(line, &i);
		}
		else if (line[i] == '\'' && (result == 0 || result == '\''))
		{
			if (result == '\'')
				result = 0;
			else
				result = '\'';
			str_forward(line, &i);
		}
	}
	return (result);
}
