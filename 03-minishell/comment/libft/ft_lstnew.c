/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:44:41 by sshin             #+#    #+#             */
/*   Updated: 2022/02/10 20:44:42 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*result;

	if (!(result = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}
