/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cnt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:03 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 10:48:23 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cmd_split.h"

void	put_quote_flag(char const *s, int *quote)
{
	if (*s == '"' && ((*quote) == 0 || (*quote) == '"'))
	{
		if ((*quote) == '"')
			(*quote) = 0;
		else
			(*quote) = '"';
	}
	else if (*s == '\'' && ((*quote) == 0 || (*quote) == '\''))
	{
		if ((*quote) == '\'')
			(*quote) = 0;
		else
			(*quote) = '\'';
	}
}

void	get_cnt(int *redir, int *cnt, int *begin, int begin_zero_flag)
{
	if (*redir)
		(*redir) = 0;
	if (begin_zero_flag == 1)
		(*begin) = 0;
	(*cnt)++;
}

// s == line
// c == ' '
void	condition_to_cnt(t_split_flag *f, char const *s, const char c, int *cnt)
{
	if (*s == c && f->quote == 0)
		get_cnt(&f->redir, cnt, &f->begin, 1);
	else if ((*s == '>' || *s == '<') && f->quote == 0)
	{
		if (f->redir == 0 && *(s - 1) != ' ')
			(*cnt)++;
		f->redir++;
	}
	else if (*s != c && *s != '\''
				&& !(*s == '>' || *s == '<')
				&& f->quote == 0
				&& (*(s - 1) == '>' || *(s - 1) == '<'))
		get_cnt(&f->redir, cnt, &f->begin, 0);
	else if (*s == '\'' && f->quote == '\''
				&& (*(s - 1) == '>' || *(s - 1) == '<'))
		get_cnt(&f->redir, cnt, &f->begin, 0);
	else if (*s == '"' && f->quote == '"'
				&& (*(s - 1) == '>' || *(s - 1) == '<'))
		get_cnt(&f->redir, cnt, &f->begin, 0);
}

// ft_split_cnt(line, ' ');
int	ft_split_cnt(char const *s, const char c)
{
	int				cnt;
	t_split_flag	f;

	cnt = 0;
	f.begin = 0;
	f.quote = 0;
	f.redir = 0;
	while (*s) // read a line
	{
		put_quote_flag(s, &f.quote);
		if (f.begin == 0)
		{
			if (*s != c)
				f.begin = 1;
			if (*s == '<' || *s == '>')
				f.redir++;
		}
		else
			condition_to_cnt(&f, s, c, &cnt);
		s++;
	}
	return (f.begin == 0 ? cnt : cnt + 1);
}
