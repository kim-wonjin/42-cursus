/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:04:51 by wokim             #+#    #+#             */
/*   Updated: 2022/03/07 16:59:21 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_rotate_same(t_stack *stack, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(stack);
		*a = *a - 1;
		*b = *b - 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(stack);
		*a = *a + 1;
		*b = *b + 1;
	}
}

void	ft_rotate_a(t_stack *stack, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(stack);
			a--;
		}
		else
		{
			rra(stack);
			a++;
		}
	}
}

void	ft_rotate_b(t_stack *stack, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(stack);
			b--;
		}
		else
		{
			rrb(stack);
			b++;
		}
	}
}
