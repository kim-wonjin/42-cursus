/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_quote_cnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:41:53 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 16:41:13 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_parse_size.h"

int	env_value_size(char *str, int size, char **envp)
{
	int	index;

	index = -1;
	while (envp[++index])
	{
		if ((!ft_strncmp(&str[1], envp[index], size))
			&& envp[index][size] == '=')
		{
			return (ft_strlen(envp[index] + size + 1));
		}
	}
	return (0);
}

int	env_key_size(char *str)
{
	int	index;

	index = 0;
	if (ft_isdigit(str[1]))
		return (1);
	while (str[++index])
	{
		if (!(ft_isalnum(str[index]) || str[index] == '_'))
			return (index - 1);
	}
	return (index - 1);
}

int	env_cnt(char *str, int *size, char **envp)
{
	int		index;
	char	*status;

	index = 0;
	if (str[1] == '?')
	{
		status = ft_itoa(g_exit_status);
		*size += ft_strlen(status);
		free(status);
		return (1);
	}
	if (str[1] == '\0' || str[1] == '\"')
	{
		*size += 1;
		return (0);
	}
	index = env_key_size(str);
	*size += env_value_size(str, index, envp);
	return (index);
}

int	d_quote_cnt(char *str, int *size, char **envp)
{
	int	index;

	index = 1;
	while (str[index] && str[index] != '\"')
	{
		if (str[index] == '$')
		{
			index += (env_cnt(&str[index], size, envp) + 1);
		}
		else
		{
			index++;
			(*size)++;
		}
	}
	return (index);
}
