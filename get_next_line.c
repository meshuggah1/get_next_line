#include "libft.h"
#include "get_next_line.h"

int			checkfd(int fd)
{
	if (fd < 0)
		return (NULL); // -1 ??
    return (0);
}

void     del(void *ptr, size_t s)
{
	free(ptr);
	(void) s;
}

char		*get_text_from_list_to_line(t_list *src, char *dst)
{
	t_list	*tmp;

	tmp = src;
	ft_lstiter(src)
	dst = ft_strcpy(dst, *(src->content));

	ft_lstdelone(&src, del);
}

int			get_next_line(const int fd, char **line)
{
    int		cfd;
    int 	ret;
    char 	buf[BUFF_SIZE + 1];
    t_list	*list;


    cfd = checkfd(fd);
    //if file - >   OPEN IT
    //if stdout - > fd == 1
    //if stdin - >  fd == 0
    while (ret = read(cfd, buf, BUFF_SIZE)) // считали из файла в массив buf кол-во бафсайз (или меньше, если строка закончилась)
	{
    	if (ret == -1)
			return (ret);
    	else if (!list)
    		list = ft_lstnew(buf, BUFF_SIZE + 1);
		else
			list = ft_lstadd(&list, ft_lstnew(buf, BUFF_SIZE + 1); // скопировали в узел списка из буфера часть строки
	}
    if (list)
    {
		*line = get_text_from_list_to_line(list, *line);
		ret = 1;
	}
    else
    	ret = 0;
	return (ret); // прочитали пустой файл
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
