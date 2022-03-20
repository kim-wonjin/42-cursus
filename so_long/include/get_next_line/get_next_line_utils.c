/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyoo <jinyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:32:02 by jinyoo            #+#    #+#             */
/*   Updated: 2022/03/18 15:58:47 by jinyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int		total_len;
	int		i;
	char	*ret;

	total_len = ft_strlen(s1) + 1;
	i = 0;
	ret = (char *)malloc(sizeof(char) * total_len);
	if (!ret)
		return (NULL);
	while (i < total_len)
	{
		ret[i] = s1[i];
		i++;
	}
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	char	*tmp;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	tmp = ret;
	while (s1[i])
		*(tmp++) = s1[i++];
	while (*s2)
		*(tmp++) = *(s2++);
	*tmp = '\0';
	free(s1);
	return (ret);
}
