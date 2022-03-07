/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:05:00 by wokim             #+#    #+#             */
/*   Updated: 2022/03/07 16:24:43 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	get_min_rotate(int a, int b, int a_rotate, int b_rotate)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	if (a_rotate < 0)
		a_rotate = a_rotate * -1;
	if (b_rotate < 0)
		b_rotate = b_rotate * -1;
	if (a + b > a_rotate + b_rotate)
		return (1);
	else
		return (0);
}

int	set_a_rotate(int num, t_stack *stack)
{
	int	a_rotate;

	if (num < get_stack_min(stack->top_a))
		a_rotate = set_a_rotate_min(stack);
	else if (num > get_stack_max(stack->top_a))
		a_rotate = set_a_rotate_max(stack);
	else
		a_rotate = set_a_rotate_mid(num, stack);
	return (a_rotate);
}

void	set_rotate(t_stack *stack, int *a, int *b)
{
	int			a_rotate;
	int			b_rotate;
	int			index;
	t_node		*stack_b;
	int			num;

	index = 0;
	stack_b = stack->top_b;
	while (index < stack->size_b)
	{
		num = stack_b->content;
		a_rotate = set_a_rotate(num, stack);
		if (index >= (stack->size_b + 1) / 2)
			b_rotate = (stack->size_b - index) * -1;
		else
			b_rotate = index;
		if (index == 0 || get_min_rotate(*a, *b, a_rotate, b_rotate))
		{
			*a = a_rotate;
			*b = b_rotate;
		}
		stack_b = stack_b->next;
		index++;
	}
}
