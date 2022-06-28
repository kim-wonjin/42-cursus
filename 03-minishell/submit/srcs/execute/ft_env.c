/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:41:14 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 16:37:29 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(t_cmd *cmd_list, char **envp, int fd)
{
	int	i;

	i = 0;
	if (cmd_list->cmdline[1].cmd != 0 && cmd_list->cmdline[i].redir_flag == 0)
	{
		cmd_list->err_manage.errcode = 3;
		cmd_list->err_manage.errindex = 1;
		return (-1);
	}
	while (envp[i])
	{
		if (haveequal(envp[i]))
		{
			ft_putstr_fd(envp[i], fd);
			ft_putchar_fd('\n', fd);
		}
		i++;
	}
	return (1);
}

char	**copy_envp(char **envs)
{
	char	**new;
	int		i;

	i = 0;
	while (envs[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (envs[++i])
		new[i] = ft_strdup(envs[i]);
	new[i] = NULL;
	return (new);
}
