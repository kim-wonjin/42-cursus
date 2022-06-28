/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:41:59 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 10:48:08 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cmd_split.h"

int	word_redirect_len(char const **s, int *len)
{
	if ((**s) == '>' || (**s) == '<')
	{
		while (**s)
		{
			if ((**s) == '>' || (**s) == '<')
				(*len)++;
			else
				return (*len);
			(*s)++;
		}
	}
	return (*len);
}

int	condition_to_len_for_word(char const *s, const char c, int *len,
								t_split_flag *f)
{
	if (f->begin == 0)
	{
		if (*s != c)
		{
			f->begin = 1;
			(*len)++;
		}
	}
	else
	{
		if (*s == c && f->quote == 0)
			return (1);
		else if ((*s == '>' || *s == '<') && f->quote == 0)
			return (1);
		else
			(*len)++;
	}
	return (0);
}

static int	ft_word_len(char const *s, const char c)
{
	int				len;
	t_split_flag	f;

	len = 0;
	f.begin = 0;
	f.quote = 0;
	if (word_redirect_len(&s, &len) != 0) // cnt redir
		return (len);
	while (*s)
	{
		put_quote_flag(s, &f.quote); // manage quotation flag
		if (condition_to_len_for_word(s, c, &len, &f) == 1)
			break ;
		s++;
	}
	return (len);
}

// ft_alloc_word(&cursor, s, c);
// s == line
// c == ' '
// 토큰에 값을 할당
char	*ft_alloc_word(int *idx, char const *s, const char c)
{
	int		word_len;
	char	*word;
	int		i;

	word_len = ft_word_len(&s[*idx], c);
	word = (char *)malloc(sizeof(char) + (word_len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < word_len)
	{
		word[i] = s[*idx + i];
		i++;
	}
	word[i] = '\0';
	*idx += word_len;
	return (word);
}
