/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:56:34 by chansong          #+#    #+#             */
/*   Updated: 2022/03/07 16:22:10 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (!lst)
		return ;
	curr = *lst;
	if (!curr)
		ft_lstadd_front(lst, new);
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = new;
		new->next = NULL;
	}
}
