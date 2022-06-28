/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:13 by sshin             #+#    #+#             */
/*   Updated: 2022/06/28 02:06:41 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_var(int *i, int *start, int (*lr_quote_pipe_flag)[2])
{
	(*i) = 0;
	(*start) = 0;
	(*lr_quote_pipe_flag)[0] = 0;
	(*lr_quote_pipe_flag)[1] = 1;
}

void	check_quote_flag(char *line, int *quote_flag, int i)
{
	if ((line[i] == '\"' || line[i] == '\'') && quote_flag[0] == 0)
		quote_flag[0] = 1;
	else if ((line[i] == '\"' || line[i] == '\'') && quote_flag[0] == 1)
		quote_flag[0] = 0;
}

void	conv_pipe_to_null_and_set_pipe_flag(int i, char *line, int *lr_quote_pipe_flag)
{
	if (line[i] == '|')
		line[i] = '\0';
	else
		lr_quote_pipe_flag[1] = 0; // line[i] == '\0'
}

void	make_lst(t_cmd **cmd_list, t_cmd **new, t_cmd **tmp, int start)
{
	if (start == 0)
	{
		*cmd_list = (*new);
		(*tmp) = *cmd_list;
	}
	else
	{
		(*cmd_list)->next = (*new);
		*cmd_list = (*cmd_list)->next;
	}
}

void	parse(t_cmd **cmd_list, char *line, char **envp)
{
	int		i;
	int		start;
	int		lr_quote_pipe_flag[2]; // [quote flag, pipe flag]
	t_cmd	*tmp;
	t_cmd	*new_node;

	init_var(&i, &start, &lr_quote_pipe_flag);
	while (1)
	{
		check_quote_flag(line, lr_quote_pipe_flag, i);
		// handle quotation // manage quotation flag
		if (line[i] == '\0' || (line[i] == '|' && (lr_quote_pipe_flag[0]) == 0))
		{
			// 명령어를 파이프 단위로 분할해서 해석한다.
			conv_pipe_to_null_and_set_pipe_flag(i, line, lr_quote_pipe_flag);
			// 파이프를 널로 대치한다. // manage pipe flag
			if ((new_node = get_new_node(&line[start], lr_quote_pipe_flag[1], envp, start)) == 0)
			// node == cmd, 파이프 단위로 분할된 명령어를 다시 토큰단위로 분할한다.
				return ;
			make_lst(cmd_list, &new_node, &tmp, start);
			// parsing 결과를 연결리스트로 제작한다.
			if (lr_quote_pipe_flag[1] == 0)
				break ;
			start = i + 1; // 파이프로 구분된 각 명령어의 시작점을 할당한다.
		}
		i++;
	}
	*cmd_list = tmp; // update list
}