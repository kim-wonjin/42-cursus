/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:03:42 by wokim             #+#    #+#             */
/*   Updated: 2022/03/07 16:52:07 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack *stack)
{
	int	tmp;

	if (stack->size_a < 2)
	{
		return ;
	}
	tmp = stack->top_a->content;
	stack->top_a->content = stack->top_a->next->content;
	stack->top_a->next->content = tmp;
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *stack)
{
	int	tmp;

	if (stack->size_b < 2)
	{
		return ;
	}
	tmp = stack->top_b->content;
	stack->top_b->content = stack->top_b->next->content;
	stack->top_b->next->content = tmp;
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack *stack)
{
	int	tmp;

	if (stack->size_a < 2)
	{
		return ;
	}
	if (stack->size_b < 2)
	{
		return ;
	}
	tmp = stack->top_a->content;
	stack->top_a->content = stack->top_a->next->content;
	stack->top_a->next->content = tmp;
	tmp = stack->top_b->content;
	stack->top_b->content = stack->top_b->next->content;
	stack->top_b->next->content = tmp;
	ft_putendl_fd("ss", 1);
}

void	pa(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size_b < 1)
		return ;
	tmp = stack->top_b;
	if (stack->size_b > 1)
	{
		stack->top_b = stack->top_b->next;
		stack->top_b->prev = NULL;
	}
	if (stack->size_a == 0)
	{
		tmp->next = NULL;
		stack->top_a = tmp;
		stack->bottom_a = tmp;
	}
	else
	{
		tmp->next = stack->top_a;
		stack->top_a->prev = tmp;
		stack->top_a = tmp;
	}
	stack->size_a += 1;
	stack->size_b -= 1;
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size_a < 1)
		return ;
	tmp = stack->top_a;
	if (stack->size_a > 1)
	{
		stack->top_a = stack->top_a->next;
		stack->top_a->prev = NULL;
	}
	if (stack->size_b == 0)
	{
		tmp->next = NULL;
		stack->top_b = tmp;
		stack->bottom_b = tmp;
	}
	else
	{
		tmp->next = stack->top_b;
		stack->top_b->prev = tmp;
		stack->top_b = tmp;
	}
	stack->size_a -= 1;
	stack->size_b += 1;
	ft_putendl_fd("pa", 1);
}
