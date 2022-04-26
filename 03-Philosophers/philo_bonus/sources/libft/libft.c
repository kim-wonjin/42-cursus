/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:02:08 by wokim             #+#    #+#             */
/*   Updated: 2022/04/26 20:02:10 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(char *)s = 0;
		++s;
		--n;
	}
}

void	*ft_calloc(size_t cnt, size_t size)
{
	void	*ret;

	ret = (void *)malloc(size * cnt);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, cnt * size);
	return (ret);
}

void	mdealloc(void **ptr)
{
	if (ptr == NULL || *ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}
