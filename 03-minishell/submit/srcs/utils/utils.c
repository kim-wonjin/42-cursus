/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:43 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 19:13:36 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_whitespace(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != 32 && !(line[i] >= 9 && line[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

char	*strjoin_path(char const *s1, char const *s2)
{
	char	*tmp1;
	char	*tmp2;
	char	*result;
	int		i;
	int		j;

	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	i = 0;
	j = 0;
	result = (char *)malloc(ft_strlen(tmp1) + ft_strlen(tmp2) + 2);
	if (result == NULL)
		return (0);
	while (tmp1[i] != '\0')
	{
		result[i] = tmp1[i];
		i++;
	}
	result[i++] = '/';
	while (tmp2[j] != '\0')
		result[i++] = tmp2[j++];
	result[i] = '\0';
	return (result);
}

void	free_list(t_cmd *cmd_list)
{
	t_cmd	*tmp;
	int		i;

	while (cmd_list->next != NULL)
	{
		i = 0;
		tmp = cmd_list;
		cmd_list = cmd_list->next;
		while (tmp->cmdline[i].cmd != NULL)
			free(tmp->cmdline[i++].cmd);
		free(tmp->cmdline);
		free(tmp->err_manage.errtoken);
		free(tmp);
	}
	i = 0;
	while (cmd_list->cmdline[i].cmd != NULL)
		free(cmd_list->cmdline[i++].cmd);
	free(cmd_list->cmdline);
	free(cmd_list->err_manage.errtoken);
	free(cmd_list);
}

t_cmd	*get_new_node(char *line, int pipe_flag, char **envp, int exit_flag)
{
	t_cmd	*result;

	result = (t_cmd *)malloc(sizeof(t_cmd));
	if (result == NULL)
		return (NULL);
	result->cmdline = get_cmdline(line, ' ', 0);
	alloc_token(result->cmdline, envp);
	result->path = NULL;
	result->pipe_flag = pipe_flag;
	if (exit_flag == 0 && pipe_flag == 0)
		result->exit_flag = 1;
	else
		result->exit_flag = 0;
	result->err_manage.errcode = 0;
	result->err_manage.errindex = 0;
	result->err_manage.errtoken = NULL;
	result->next = NULL;
	return (result);
}
