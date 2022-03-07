/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:05:05 by wokim             #+#    #+#             */
/*   Updated: 2022/03/07 16:24:57 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_sort_a_three(t_stack *stack)
{
	int	top;
	int	mid;
	int	bot;

	top = stack->top_a->content;
	mid = stack->top_a->next->content;
	bot = stack->top_a->next->next->content;
	if (top > mid && mid > bot && top > bot)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > mid && bot > mid && top > bot)
		ra(stack);
	else if (mid > top && mid > bot && bot > top)
	{
		sa(stack);
		ra(stack);
	}
	else if (top > mid && bot > mid && bot > top)
		sa(stack);
	else if (mid > top && mid > bot && top > bot)
		rra(stack);
}

void	ft_sort_big(t_stack *stack)
{
	int	a;
	int	b;

	ft_sort_pivot(stack);
	while (stack->size_a > 3)
		pb(stack);
	if (stack->size_a == 2)
	{
		if (stack->top_a->content > stack->top_a->next->content)
			sa(stack);
	}
	if (stack->size_a == 3)
		ft_sort_a_three(stack);
	while (stack->size_b)
	{
		a = 0;
		b = 0;
		set_rotate(stack, &a, &b);
		ft_rotate_same(stack, &a, &b);
		ft_rotate_a(stack, a);
		ft_rotate_b(stack, b);
		pa(stack);
	}
	ft_sort_big_last(stack);
}

void	ft_sort(t_stack *stack)
{
	if (stack->size_a == 2)
	{
		if (stack->top_a->content > stack->top_a->next->content)
			sa(stack);
	}
	else if (stack->size_a == 3)
	{
		ft_sort_a_three(stack);
	}
	else
	{
		ft_sort_big(stack);
	}
}
