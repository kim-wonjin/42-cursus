/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:05:03 by wokim             #+#    #+#             */
/*   Updated: 2022/03/07 16:24:50 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_sort_big_last(t_stack *stack)
{
	int	min_rotate;

	min_rotate = set_a_rotate_min(stack);
	while (min_rotate)
	{
		if (min_rotate > 0)
		{
			ra(stack);
			min_rotate--;
		}
		else
		{
			rra(stack);
			min_rotate++;
		}
	}
}

void	ft_sort_three_part(t_stack *stack, int pivot1, int pivot2)
{
	if (stack->top_a->content < pivot1)
	{
		pb(stack);
		rb(stack);
	}
	else if (stack->top_a->content < pivot2)
		pb(stack);
	else
		ra(stack);
}

void	ft_sort_pivot(t_stack *stack)
{
	int	index;
	int	pivot1;
	int	pivot2;

	index = stack->size_a / 3;
	pivot1 = stack->array[index];
	index = stack->size_a * 2 / 3;
	pivot2 = stack->array[index];
	index = stack->size_a;
	while (index)
	{
		ft_sort_three_part(stack, pivot1, pivot2);
		index--;
	}
}
