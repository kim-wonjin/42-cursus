/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parse_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:08 by sshin             #+#    #+#             */
/*   Updated: 2022/02/10 20:55:22 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_parse_size.h"

int	unclosed_quote(char *str, char quote)
{
	int	index;

	index = 1;
	while (str[index] && str[index] != quote)
		index++;
	if (str[index] == '\0')
		return (0);
	return (1);
}

int	s_quote_cnt(char *str, int *size)
{
	int	index;

	index = 1;
	while (str[index] && str[index] != '\'')
	{
		index++;
		(*size)++;
	}
	return (index);
}

// get_parse_size(tmp_cmd, envp);
int	get_parse_size(char *str, char **envp)
{
	int	index;
	int	size;

	size = 0;
	index = -1;
	while (str[++index])
	{
		if (str[index] == '\'' && unclosed_quote(&str[index], '\''))
			index += s_quote_cnt(&str[index], &size);
			// single quote 처리
		else if (str[index] == '\"' && unclosed_quote(&str[index], '\"'))
			index += d_quote_cnt(&str[index], &size, envp);
			// double quote 처리
		else if (str[index] == '$')
			index += env_cnt(&str[index], &size, envp);
			// 환경변수의 key와 value의 길이를 처리
			// key의 길이는 index에 반영되고, value의 길이는 *size에 반영된다.
		else if (str[index])
			size++;
	}
	return (size);
}
