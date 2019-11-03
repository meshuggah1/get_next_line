#include "get_next_line.h"

void        chars_to_line(char **line, char *strcpy, int i)
{
	char *tmp;

	if (!*line || !(**line))
	{
		tmp = ft_strsub(strcpy, 0, i); // кладем все до новой строки (или конца буфера) включительно
		free(*line);
		*line = tmp;
	}
	else
	{
		tmp = ft_strjoin(*line, ft_strsub(strcpy, 0, i));  // дополняем если в буфере поместилось меньше, чем строка до \n
		free(*line);
		*line = tmp;
	}
}

int        str_and_fd(char *ptr, char **line, char **o)
{
	size_t i;
	char *strcpy;

	//ptr = сохранненая в fd_list часть строки или буфер с новой строкой
	strcpy = ft_strdup(ptr);
	i = 0;
	while (i < BUFF_SIZE && strcpy[i] != '\n' && strcpy[i])
		i++;
	chars_to_line(line, strcpy, i);
	ft_strdel(o);
	if (strcpy[i] == '\n')
	{
		*o = ft_strdup(&(strcpy[i + 1])); // оставляем в fd_list хранить все, что после новой строки
		ft_strdel(&strcpy);
		return (1);
	}
	ft_strdel(&strcpy);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char *f_list[OPEN_MAX];
	int ret;
	char buf[BUFF_SIZE + 1];

	ret = 0;
	if (fd < 0 || !line)
		return (-1);
	*line = ft_memalloc(1);
	if (f_list[fd] && *f_list[fd])                                           // если огрызок есть, сначала читаем его
	{
		ret = str_and_fd(f_list[fd], line, &f_list[fd]); // если вернули 1, то считали строку
		if (ret)                                             // в огрызке была новая строка - считали, можно выходить
			return (1);
		// далее идем если (1)огрызка не было или (2)в нем не было новой строки
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))                 // считали из файла в массив buf кол-во бафсайз (или меньше, если строка закончилась)
	{
		if (ret == -1)
			return (ret);
		buf[ret] = '\0';
		ret = str_and_fd(buf, line, &f_list[fd]);
		ft_bzero(buf, BUFF_SIZE);
		if (ret == 1)
			break;
	}
	return (ret);
}

/*
 * The return value can be 1, 0 or -1 depending on whether a line has been read,
when the reading has been completed, or if an error has happened respectively.
 *
 * There cannot be a main function in your program.
• Do not push a Makefile.
 All heap allocated memory space must be properly freed when necessary.
• Your project cannot have memory leaks.
 */