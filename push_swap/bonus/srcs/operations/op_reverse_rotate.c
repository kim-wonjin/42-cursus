/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:03:37 by wokim             #+#    #+#             */
/*   Updated: 2022/03/07 16:52:12 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size_a < 2)
	{
		return ;
	}
	tmp = stack->bottom_a;
	stack->bottom_a = stack->bottom_a->prev;
	stack->bottom_a->next = NULL;
	stack->top_a->prev = tmp;
	tmp->next = stack->top_a;
	stack->top_a = tmp;
	stack->top_a->prev = NULL;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size_b < 2)
	{
		return ;
	}
	tmp = stack->bottom_b;
	stack->bottom_b = stack->bottom_b->prev;
	stack->bottom_b->next = NULL;
	stack->top_b->prev = tmp;
	tmp->next = stack->top_b;
	stack->top_b = tmp;
	stack->top_b->prev = NULL;
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size_b < 2 || stack->size_a < 2)
	{
		return ;
	}
	tmp = stack->bottom_a;
	stack->bottom_a = stack->bottom_a->prev;
	stack->bottom_a->next = NULL;
	stack->top_a->prev = tmp;
	tmp->next = stack->top_a;
	stack->top_a = tmp;
	stack->top_a->prev = NULL;
	tmp = stack->bottom_b;
	stack->bottom_b = stack->bottom_b->prev;
	stack->bottom_b->next = NULL;
	stack->top_b->prev = tmp;
	tmp->next = stack->top_b;
	stack->top_b = tmp;
	stack->top_b->prev = NULL;
	ft_putendl_fd("rrr", 1);
}
