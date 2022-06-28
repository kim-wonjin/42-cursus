/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:40:54 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 16:30:36 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**sort_env(char **envp)
{
	int		i;
	int		j;
	char	**new;
	char	*temp;

	new = copy_envp(envp);
	i = 0;
	while (new[i])
	{
		j = i + 1;
		while (new[j])
		{
			if (ft_strncmp(new[i], new[j], ft_strlen(new[i])) > 0)
			{
				temp = new[i];
				new[i] = new[j];
				new[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (new);
}

int	cnt_envp_row(char **envp)
{
	int	row;

	row = 0;
	while (envp[row])
		row++;
	return (row);
}

int	isvalid_export(char *line)
{
	char	**str_arr;
	char	*key;
	int		i;
	int		ret;

	i = 0;
	str_arr = ft_split(line, '=');
	key = str_arr[0];
	ret = ft_valid_key(key);
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
	return (ret);
}

int	haveequal(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	add_key_envp(char ***envp, char *cmd, int keyindex)
{
	free((*envp)[keyindex]);
	(*envp)[keyindex] = ft_strdup(cmd);
}
