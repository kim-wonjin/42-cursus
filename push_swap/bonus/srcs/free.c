/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:04:18 by wokim             #+#    #+#             */
/*   Updated: 2022/03/07 16:51:52 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_a(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	node = stack->top_a;
	while (node)
	{
		if (node->next)
			temp = node->next;
		else
			temp = NULL;
		free(node);
		if (temp)
			node = temp;
		else
			break ;
	}
	free(stack);
}

void	free_b(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	node = stack->top_b;
	while (node)
	{
		if (node->next)
			temp = node->next;
		else
			temp = NULL;
		free(node);
		if (temp)
			node = temp;
		else
			break ;
	}
	free(stack);
}
