/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:41:24 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 19:15:03 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_quote(char *str, int fd)
{
	int	i;

	i = 0;
	if (haveequal(str))
	{
		while (str[i] != '=')
			i++;
		write(fd, str, ++i);
		write(fd, "\"", 1);
		write(fd, str + i, ft_strlen(str + i));
		write(fd, "\"", 1);
	}
	else
	{
		while (str[i])
			i++;
		write(fd, str, ++i);
	}
}

void	print_export(char **envp, int fd)
{
	int		i;
	char	**sorted;

	i = 0;
	sorted = sort_env(envp);
	while (sorted[i])
	{
		ft_putstr_fd("declare -x ", fd);
		print_quote(sorted[i], fd);
		ft_putchar_fd('\n', fd);
		free(sorted[i]);
		i++;
	}
	free(sorted);
}

int	check_key(char **envp, char *line)
{
	int	i;
	int	key;

	i = 0;
	key = 0;
	if (haveequal(line))
	{
		while (line[key] != '=')
			key++;
	}
	else
	{
		while (line[key])
			key++;
	}
	while (envp[i])
	{
		if (ft_strncmp(envp[i], line, key) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	add_envp(char *cmd, char ***envp)
{
	char	**new;
	int		row;
	int		i;

	i = 0;
	row = cnt_envp_row(*envp);
	new = (char **)malloc(sizeof(char *) * (row + 2));
	if (new == NULL)
		return (0);
	while ((*envp)[i])
	{
		new[i] = ft_strdup((*envp)[i]);
		free((*envp)[i]);
		i++;
	}
	free(*envp);
	new[i] = ft_strdup(cmd);
	new[++i] = NULL;
	*envp = new;
	return (1);
}

int	ft_export(t_cmd *cmd_list, char ***envp, int fd)
{
	int	i;
	int	keyindex;

	i = 1;
	while (cmd_list->cmdline[i].cmd && cmd_list->cmdline[i].redir_flag == 0)
	{
		if (isvalid_export(cmd_list->cmdline[i].cmd))
		{
			keyindex = check_key(*envp, cmd_list->cmdline[i].cmd);
			if (keyindex >= 0 && haveequal(cmd_list->cmdline[i].cmd))
				add_key_envp(envp, cmd_list->cmdline[i].cmd, keyindex);
			else
				add_envp(cmd_list->cmdline[i].cmd, envp);
		}
		else
			cmd_list->err_manage.errcode = 5;
		i++;
	}
	if (!(cmd_list->cmdline[1].cmd) || cmd_list->cmdline[1].redir_flag == 1)
		print_export(*envp, fd);
	if (cmd_list->err_manage.errcode == 5)
		return (-1);
	return (1);
}
