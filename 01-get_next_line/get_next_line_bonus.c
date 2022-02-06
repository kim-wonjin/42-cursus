/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:16:30 by wokim             #+#    #+#             */
/*   Updated: 2021/07/01 22:15:13 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	find_newline(char *backup)
{
	int	i;

	i = 0;
	if (backup == NULL)
		return (-1);
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	split_line(int split_idx, char **backup, char **line)
{
	char *tmp;

	if (!(tmp = ft_strdup(*backup)))
		return (-1);
	(*backup)[split_idx] = '\0';
	if (!(*line = ft_strdup(*backup)))
	{
		free(*backup);
		return (-1);
	}
	free(*backup);
	if (!(*backup = ft_strdup(tmp + split_idx + 1)))
		return (-1);
	free(tmp);
	return (1);
}

int	split_after_eof(char **backup, char **line)
{
	int	split_idx;

	if ((split_idx = find_newline(*backup)) >= 0 && *backup)
		return (split_line(split_idx, backup, line));
	else if (*backup)
	{
		*line = *backup;
		*backup = NULL;
	}
	else if (!(*line = ft_strdup("")))
		return (-1);
	free(*backup);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char *backup[OPEN_MAX];
	char		*buf;
	int			r_bytes;
	int			split_idx;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((r_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r_bytes] = '\0';
		if (!(backup[fd] = ft_strjoin(backup[fd], buf)))
			return (-1);
		if ((split_idx = find_newline(backup[fd])) >= 0)
		{
			free(buf);
			return (split_line(split_idx, &backup[fd], line));
		}
	}
	free(buf);
	if (r_bytes == 0)
		return (split_after_eof(&backup[fd], line));
	return (-1);
}
