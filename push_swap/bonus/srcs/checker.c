/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:04:13 by wokim             #+#    #+#             */
/*   Updated: 2022/03/07 16:51:57 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top_a;
	while (node)
	{
		if (node->next)
		{
			if (node->content > node->next->content)
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	if (node->content == stack->bottom_a->content)
		return (1);
	else
		return (0);
}

void	check_operation(char *buf, t_stack *stack)
{
	if (!ft_strcmp("pa", buf) || !ft_strcmp("pb", buf))
		do_push(buf, stack);
	else if (!ft_strcmp("sa", buf) || !ft_strcmp("sb", buf)
		|| !ft_strcmp("ss", buf))
		do_swap(buf, stack);
	else if (!ft_strcmp("ra", buf) || !ft_strcmp("rb", buf)
		|| !ft_strcmp("rr", buf))
		do_rotate(buf, stack);
	else if (!ft_strcmp("rra", buf) || !ft_strcmp("rrb", buf)
		|| !ft_strcmp("rrr", buf))
		do_reverse_rotate(buf, stack);
	else
		print_error(1);
}

void	checker(t_stack *stack)
{
	char	*buf;

	while (get_next_line(0, &buf) > 0)
	{
		check_operation(buf, stack);
		free(buf);
	}
	free(buf);
	if (check_sorted(stack) && !stack->top_b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}
