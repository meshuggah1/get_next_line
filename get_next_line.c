#include "libft.h"
#include "get_next_line.h"
static t_list *fd_list[OPEN_MAX];

t_list		*checkfd(int fd)
{
	t_list	*list;
	char buf[BUFF_SIZE];

	if (fd < 0)
		return (NULL);
	if (fd_list[fd] != NULL)
		list = fd_list[fd];
	return (list);
}

void     	del(void *ptr, size_t s)
{
	free(ptr);
	(void) s;
}
/*
char		*get_text_from_list_to_line(t_list *src, char *dst)
{
	t_list	*tmp;

	tmp = src;
	ft_lstiter(src)
	dst = ft_strcpy(dst, *(src->content));

	ft_lstdelone(&src, del);
}
*/

void		check_buf(char *buf, const int fd)
{
	size_t i;

	i = 0;
	while (*buf != '\n' && *buf != '\0')
	{
		printf("%zu-ый символ буфера = %c\n", i, *buf);
		buf++;
		i++;
	}
	if (*buf == '\n')
	{
		printf("нашел символ новой строки! теперь там слэш ноль\n");
		*buf = '\0';
		buf++;
		printf("перешел на след символ и это = %c\n", *buf);
		printf("смотрю в fd_list, там %p\n", fd_list[fd]);
		if (fd_list[fd] == NULL)
			fd_list[fd] = ft_lstnew(buf, i);
		else {
			fd_list[fd]->content = buf;
			fd_list[fd]->content_size = i;
		}
		printf("теперь там content = %s\n", fd_list[fd]->content);
	}
	return ;
}

int			fromReadToList(t_list *list, const int fd)
{
	int ret;
	int flag;
	char buf[BUFF_SIZE];

	flag = 1;
	while ((ret = read(fd, buf, BUFF_SIZE))) // считали из файла в массив buf кол-во бафсайз (или меньше, если строка закончилась)
	{
		if (ret == -1)
			return (ret);
		printf("в буфере = %s \n", buf);
		printf("проверяю буфер... \n");
		check_buf(buf, fd);
		if (flag == 1)
		{
			list = ft_lstnew(buf, BUFF_SIZE);
			flag = 0;
		}
		else if (ret != 1)                                // если остался только \n для него уже не создаем лист
			ft_lstadd(&list, ft_lstnew(buf, BUFF_SIZE)); // скопировали в узел списка из буфера часть строки
	}
	//<===== CHECK =====>
	while (1)
	{
		printf("content = %s\n", list->content);
		list = list->next;
		if (list == NULL)
			break ;
	}
	//<===== CHECK =====>
	if (flag == 1) {
		printf("flag =1 wtf");
		return (0);
	}

	else
		return (1);
}

int			get_next_line(const int fd, char **line)
{
	t_list	*list;
	int ret;
	list = checkfd(fd);
	ret = fromReadToList(list, fd);
	//<===== CHECK =====>
	//<===== CHECK =====>

	//if file - >   OPEN IT
	//if stdout - > fd == 1
	//if stdin - >  fd == 0

	// if (list)
	// {
	//	*line = get_text_from_list_to_line(list, *line);
	//	ret = 1;
	//}
	return (ret); // ret = 1, 0 , -1
}

int main()
{
	char *ptr = (char *)malloc(sizeof(*ptr) * 500);
	printf("vyzov GNL dlya a...\n");
	get_next_line(open("a", O_RDONLY), &ptr);
	//printf("vyzov GNL dlya b...\n");
	//get_next_line(open("b", O_RDONLY), &ptr);
	//printf("vyzov GNL dlya a...\n");
	//get_next_line(open("a", O_RDONLY), &ptr);
	//printf("vyzov GNL dlya b...\n");
	//get_next_line(open("b", O_RDONLY), &ptr);
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
