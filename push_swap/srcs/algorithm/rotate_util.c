/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:04:53 by wokim             #+#    #+#             */
/*   Updated: 2022/03/07 16:24:35 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	get_stack_min(t_node *stack)
{
	int	ret;

	ret = stack->content;
	while (stack)
	{
		if (ret > stack->content)
		{
			ret = stack->content;
		}
		stack = stack->next;
	}
	return (ret);
}

int	set_a_rotate_min(t_stack *stack)
{
	int			ret;
	int			a_minimum;
	int			tmp;
	t_node		*stack_a;

	ret = 0;
	tmp = 0;
	stack_a = stack->top_a;
	a_minimum = get_stack_min(stack_a);
	while (stack_a)
	{
		tmp = stack_a->content;
		if (tmp == a_minimum)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	if (ret >= (stack->size_a + 1) / 2)
		ret = (stack->size_a - ret) * -1;
	return (ret);
}

int	get_stack_max(t_node *stack)
{
	int	ret;

	ret = stack->content;
	while (stack)
	{
		if (ret < stack->content)
		{
			ret = stack->content;
		}
		stack = stack->next;
	}
	return (ret);
}

int	set_a_rotate_max(t_stack *stack)
{
	int			ret;
	int			a_maximum;
	int			tmp;
	t_node		*stack_a;

	ret = 0;
	tmp = 0;
	stack_a = stack->top_a;
	a_maximum = get_stack_max(stack_a);
	while (stack_a)
	{
		tmp = stack_a->content;
		if (tmp == a_maximum)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	ret++;
	if (ret >= (stack->size_a + 1) / 2)
		ret = (stack->size_a - ret) * -1;
	return (ret);
}

int	set_a_rotate_mid(int num, t_stack *stack)
{
	t_node		*stack_a;
	int			ret;

	stack_a = stack->top_a;
	ret = 1;
	while (stack_a->next)
	{
		if (num > stack_a->content && num < stack_a->next->content)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	if (ret >= (stack->size_a + 1) / 2)
		ret = (stack->size_a - ret) * -1;
	return (ret);
}
