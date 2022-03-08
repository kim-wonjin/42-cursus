/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:04:15 by wokim             #+#    #+#             */
/*   Updated: 2022/03/07 16:51:55 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_push(char *buf, t_stack *stack)
{
	if (!ft_strcmp("pa", buf))
		pa(stack);
	else if (!ft_strcmp("pb", buf))
		pb(stack);
}

void	do_swap(char *buf, t_stack *stack)
{
	if (!ft_strcmp("sa", buf))
		sa(stack);
	else if (!ft_strcmp("sb", buf))
		sb(stack);
	else
		ss(stack);
}

void	do_rotate(char *buf, t_stack *stack)
{
	if (!ft_strcmp("ra", buf))
		ra(stack);
	else if (!ft_strcmp("rb", buf))
		rb(stack);
	else
		rr(stack);
}

void	do_reverse_rotate(char *buf, t_stack *stack)
{
	if (!ft_strcmp("rra", buf))
		rra(stack);
	else if (!ft_strcmp("rrb", buf))
		rrb(stack);
	else
		rrr(stack);
}
