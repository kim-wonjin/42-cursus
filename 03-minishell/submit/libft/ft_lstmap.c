/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:44:37 by sshin             #+#    #+#             */
/*   Updated: 2022/06/27 00:10:25 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_next;
	t_list	*curr;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_head = ft_lstnew(f(lst->content));
	if (new_head == NULL)
		return (NULL);
	curr = new_head;
	lst = lst->next;
	while (lst)
	{
		new_next = ft_lstnew(f(lst->content));
		if (new_next == NULL)
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		curr->next = new_next;
		curr = new_next;
		lst = lst->next;
	}
	return (new_head);
}
