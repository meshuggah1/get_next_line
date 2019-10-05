##include "libft.h"
#include "get_next_line.h"

t_list		*checkfd(int fd, t_list *fd_list[])
{
	t_list	*list;
	char buf[BUFF_SIZE + 1];

	if (fd < 0)
		return (NULL); // -1 ??
	if (fd_list[fd] != NULL)
		list = fd_list[fd];
	return (list);
}
/*
void     	del(void *ptr, size_t s)
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
*/
int			fromReadToList(t_list *list, const int fd)
{
	int ret;
	int flag;
	char buf[BUFF_SIZE + 1];

	flag = 1;
	while ((ret = read(fd, buf, BUFF_SIZE))) // считали из файла в массив buf кол-во бафсайз (или меньше, если строка закончилась)
	{

		if (ret == -1)
			return (ret);
		else if (flag == 1)
		{
			printf("ret == %d\n", ret);
			list = ft_lstnew(buf, BUFF_SIZE + 1);
			flag = 0;
		}
		else if (ret != 1)                                // если остался только \n для него уже не создаем лист
			ft_lstadd(&list, ft_lstnew(buf, BUFF_SIZE + 1)); // скопировали в узел списка из буфера часть строки
	}
	if (flag == 1) {
		printf("flag =1 wtf");
		return (0);
	}
	else return (1);
}

int			get_next_line(const int fd, char **line)
{
	t_list	*list;
	t_list	*fd_list[OPEN_MAX];
	int ret;

	list = checkfd(fd, fd_list);
	ret = fromReadToList(list, fd);

	// if (list)
	// {
	//	*line = get_text_from_list_to_line(list, *line);
	//	ret = 1;
	//}
	return (ret); // ret = 1, 0 , -1
}

int			main()
{
	char *ptr = (char *)malloc(sizeof(*ptr) * 500);
	get_next_line(open("a", O_RDONLY), &ptr);
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
