/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:01:30 by wokim             #+#    #+#             */
/*   Updated: 2022/03/07 16:52:15 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strlen_gnl(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin_gnl(char *save, char *buff)
{
	int		i;
	int		j;
	int		save_len;
	int		buff_len;
	char	*dest;

	save_len = ft_strlen_gnl(save);
	buff_len = ft_strlen_gnl(buff);
	dest = (char *)malloc(save_len + buff_len + 1);
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < save_len)
		dest[i] = save[i];
	j = -1;
	while (++j < buff_len)
		dest[i + j] = buff[j];
	dest[i + j] = '\0';
	free(save);
	return (dest);
}
