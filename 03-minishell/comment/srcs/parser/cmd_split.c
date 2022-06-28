/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:41:49 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 10:30:02 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cmd_split.h"

static void	*ft_free(t_token *result, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(result[i++].cmd);
	return (NULL);
}

// result->cmdline = cmd_split(line, ' ');
t_token	*get_cmdline(char const *s, char c)
{
	int		i;
	int		cursor;
	t_token	*result;

	if (s == NULL)
		return (NULL);
	i = 0;
	cursor = 0;
	result = (t_token *)malloc(sizeof(t_token) * (ft_split_cnt(s, c) + 1));
	// (1) 토큰 개수 산정
	// (2) 토큰 제작
	if (result == NULL)
		return (NULL);
	while (s[cursor])
		if (s[cursor] == c) // skip spc
			cursor++;
		else
		{
			result[i].cmd = ft_alloc_word(&cursor, s, c);
			// (3) 토큰에 값을 할당
			result[i].redir_flag = 0;
			// (4) Initialize redirection flag
			if (result[i].cmd == NULL)
				return (ft_free(result, i));
			i++;
		}
	result[i].cmd = 0;
	return (result);
}
