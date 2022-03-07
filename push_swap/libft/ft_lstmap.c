/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:56:57 by chansong          #+#    #+#             */
/*   Updated: 2022/03/07 16:22:29 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*res_curr;

	if (!lst || !f)
		return (NULL);
	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = f(lst->content);
	res_curr = res;
	lst = lst->next;
	while (lst)
	{
		res_curr->next = (t_list *)malloc(sizeof(t_list));
		if (!res_curr)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		res_curr = res_curr->next;
		res_curr->content = f(lst->content);
		lst = lst->next;
	}
	res_curr->next = NULL;
	return (res);
}
