#include "get_next_line.h"
# include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("a", O_RDONLY);

	char **line;
	int gnl;
	line = ft_memalloc(1);;

	while ((gnl = get_next_line(fd, line)) > 0)
	{
		printf("%d ", gnl);
		printf("%s\n", *line);
		free(*line);
	}
	printf("%d ", gnl);
	if (gnl > 0)
		free(*line);
	return (0);
}