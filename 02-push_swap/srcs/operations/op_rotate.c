/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:03:39 by wokim             #+#    #+#             */
/*   Updated: 2022/03/07 16:25:44 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size_a < 2)
	{
		return ;
	}
	tmp = stack->top_a;
	stack->top_a = stack->top_a->next;
	stack->top_a->prev = NULL;
	stack->bottom_a->next = tmp;
	tmp->prev = stack->bottom_a;
	stack->bottom_a = tmp;
	stack->bottom_a->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size_b < 2)
	{
		return ;
	}
	tmp = stack->top_b;
	stack->top_b = stack->top_b->next;
	stack->top_b->prev = NULL;
	stack->bottom_b->next = tmp;
	tmp->prev = stack->bottom_b;
	stack->bottom_b = tmp;
	stack->bottom_a->next = NULL;
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size_b < 2 || stack->size_a < 2)
	{
		return ;
	}
	tmp = stack->top_a;
	stack->top_a = stack->top_a->next;
	stack->top_a->prev = NULL;
	stack->bottom_a->next = tmp;
	tmp->prev = stack->bottom_a;
	stack->bottom_a = tmp;
	stack->bottom_a->next = NULL;
	tmp = stack->top_b;
	stack->top_b = stack->top_b->next;
	stack->top_b->prev = NULL;
	stack->bottom_b->next = tmp;
	tmp->prev = stack->bottom_b;
	stack->bottom_b = tmp;
	stack->bottom_a->next = NULL;
	ft_putendl_fd("rr", 1);
}
