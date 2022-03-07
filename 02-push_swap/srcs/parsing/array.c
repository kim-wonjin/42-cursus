/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:04:37 by wokim             #+#    #+#             */
/*   Updated: 2022/03/07 16:25:58 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_array_size(int argc, char *argv[])
{
	int		i;
	int		size;
	char	**split;

	i = 0;
	size = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		size += ft_split_size(split);
		ft_free(split);
		i++;
	}
	return (size - 1);
}

int	*ft_set_array(int argc, char *argv[], int array_size)
{
	int		argc_i;
	int		arr_i;
	int		split_i;
	int		*array;
	char	**split;

	argc_i = 1;
	arr_i = 0;
	array = (int *)malloc(sizeof(int) * array_size);
	if (!array)
		print_error(1);
	while (argc_i < argc)
	{
		split = ft_split(argv[argc_i], ' ');
		split_i = 0;
		while (split[split_i])
		{
			array[arr_i++] = ft_check_atoi(split[split_i]);
			split_i++;
		}
		ft_free(split);
		argc_i++;
	}
	array[arr_i] = '\0';
	return (array);
}

void	ft_set_stack(t_stack *stack, int *array, int array_size)
{
	t_node	*new_node;
	int		i;

	i = 0;
	while (i < array_size)
	{
		new_node = init_node();
		stack->size_a += 1;
		stack->bottom_a->content = (int)array[i];
		stack->bottom_a->next = new_node;
		new_node->prev = stack->bottom_a;
		stack->bottom_a = new_node;
		i++;
	}
	stack->bottom_a = stack->bottom_a->prev;
	free(new_node);
}

void	ft_array_sort(int *array, int array_size, int index)
{
	int	j;
	int	tmp;
	int	sorted;

	sorted = 0;
	while (index < array_size)
	{
		j = 0;
		while (j < array_size - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				sorted++;
			}
			j++;
		}
		if (array[index] == array[index + 1])
			print_error(1);
		index++;
	}
	if (sorted == 0)
		print_error(-1);
}
