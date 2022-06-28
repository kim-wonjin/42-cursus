/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:44:12 by sshin             #+#    #+#             */
/*   Updated: 2022/02/10 20:44:13 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new1)
{
	t_list	*last;

	if (lst == NULL || new1 == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new1;
		return ;
	}
	last = ft_lstlast(*lst);
	new1->next = last->next;
	last->next = new1;
}
