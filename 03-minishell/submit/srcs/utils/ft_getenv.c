/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:35 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 16:53:53 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_getenv.h"

char	*get_env_value(char *key, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if ((!ft_strncmp(key, envp[i], ft_strlen(key)))
			&& envp[i][ft_strlen(key)] == '=')
			return (envp[i] + ft_strlen(key) + 1);
	}
	return ("");
}
