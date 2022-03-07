/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:03:14 by wokim             #+#    #+#             */
/*   Updated: 2022/03/07 16:21:04 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"
# include "get_next_line_bonus.h"

typedef struct s_node
{
	struct s_node	*prev;
	int				content;
	struct s_node	*next;
}			t_node;

typedef struct s_stack
{
	int				*array;
	int				size_a;
	struct s_node	*top_a;
	struct s_node	*bottom_a;
	int				size_b;
	struct s_node	*top_b;
	struct s_node	*bottom_b;
}			t_stack;

/*
	main.c
*/
int			print_error(int type);
t_node		*init_node(void);
t_stack		*init_stack(void);
int			main(int argc, char *argv[]);

/*
	checker.c
*/
void		checker(t_stack *stack);
void		check_operation(char *buf, t_stack *stack);
int			check_sorted(t_stack *stack);

/*
	do_operation.c
*/
void		do_push(char *buf, t_stack *stack);
void		do_swap(char *buf, t_stack *stack);
void		do_rotate(char *buf, t_stack *stack);
void		do_reverse_rotate(char *buf, t_stack *stack);

/*
	free.c
*/
void		free_a(t_stack *stack);
void		free_b(t_stack *stack);

/*
	array.c
*/
int			ft_array_size(int argc, char *argv[]);
int			*ft_set_array(int argc, char *argv[], int array_size);
void		ft_set_stack(t_stack *stack, int *array, int array_size);
void		ft_array_sort(int *array, int array_size, int index);

/*
	util.c
*/
int			ft_split_size(char **split);
void		ft_free(char **str);
int			ft_check_atoi(const char *str);

/*
	op_swap_push.c
*/
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack);
void		pa(t_stack *stack);
void		pb(t_stack *stack);

/*
	op_rotate.c
*/
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);

/*
	op_reverse_rotate.c
*/
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack);

#endif
