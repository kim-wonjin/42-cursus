/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_env_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:41:38 by sshin             #+#    #+#             */
/*   Updated: 2022/02/10 20:52:41 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/alloc_token.h"
#include "../../includes/get_parse_size.h"

int	get_envkey(char *src, char **key)
{
	int	key_len;

	key_len = env_key_size(src);
	*key = ft_substr(src, 1, key_len);
	return (key_len);
}

int	next_quote_or_null(char *src, char ***dest)
{
	if (src[1] == '\0' || src[1] == '\"')
	{
		(***dest) = '$';
		(**dest) += 1;
		return (0);
	}
	return (1);
}
