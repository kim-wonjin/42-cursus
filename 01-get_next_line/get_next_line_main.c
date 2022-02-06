#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int		main(void)
{
	int		fd;
	char	*line;
	int		res;

	fd = open("testfile", O_RDONLY);
	while (1)
	{
		res = get_next_line(fd, &line);
		printf("%d\n", res);
		if (res != -1)
		{
			printf("%s\n", line);
			free(line);
		}
		if (!res || res == -1)
			break;
	}
	close(fd);
	fd = open("testfile", O_RDONLY);
	while (1)
	{
		res = get_next_line(fd, &line);
		printf("%d\n", res);
		if (res != -1)
		{
			printf("%s\n", line);
			free(line);
		}
		if (!res || res == -1)
			break;
	}
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
