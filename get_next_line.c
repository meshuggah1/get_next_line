##include <stdio.h>
#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"
static t_list *fd_list[OPEN_MAX];

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

int		check_buf(char *buf, const int fd)
{
    size_t i;
    int lineRead;
    char *before_n;

    before_n = buf;          // отсюда будем брать для списка часть строки до \n
    lineRead = 0;
    i = 0;
    while (*buf != '\n' && *buf != '\0' && i < BUFF_SIZE)
    {
        printf("%zu-ый символ буфера = %c\n", i, *buf);
        buf++;
        i++;
    }
    if (*buf == '\n')
    {
        lineRead = 1;
        printf("нашел символ новой строки! теперь там ноль\n");
        *buf = '\0';
        buf++;
        printf("перешел на след символ и это: %c\n", *buf);
        printf("buf = %s\n", buf);
        if (i > 0)                          // если i > 0, то в буфере перед \n что-то было, кладем это в список
        {
            if (fd_list[fd] == NULL)
                fd_list[fd] = ft_lstnew(before_n, ft_strlen(before_n));
            else // возможно, этот else не нужен
                ft_lstadd(&(fd_list[fd]), ft_lstnew(before_n, ft_strlen(before_n)));
            printf("в check_ buf: создан узел списка с адресом: %p\n", fd_list[fd]);
            printf("в check_ buf: в нем: %s\n", fd_list[fd]->content);
            printf("в check_ buf: указывает на: %p\n", fd_list[fd]->next);
            printf("смотрю в fd_list, там %p\n", fd_list[fd]);

            //   free(before_n);
        }
        if (ft_isprint(*buf))              // если в буфере после \n что-то осталось, кладем остаток в список
        {
            if (fd_list[fd] == NULL)
                fd_list[fd] = ft_lstnew(buf, ft_strlen(buf));
            else  // возможно, этот else не нужен
                ft_lstadd(&(fd_list[fd]), ft_lstnew(buf, ft_strlen(buf)));
            printf("в check_ buf: создан узел списка для огрызка с адресом: %p\n", fd_list[fd]);
            printf("в check_ buf: в нем: %s\n", fd_list[fd]->content);
            printf("в check_ buf: указывает на: %p\n", fd_list[fd]->next);
        }
    }
    return (lineRead);
}

int			fromReadToList(const int fd)
{
    int ret;
    char buf[BUFF_SIZE];
    int lineR;

    lineR = 0;
    while ((ret = read(fd, buf, BUFF_SIZE))) // считали из файла в массив buf кол-во бафсайз (или меньше, если строка закончилась)
    {
        if (ret == -1)
            return (ret);
        printf("в буфере: %s\n", buf);
        printf("проверяю буфер... \n");
        lineR = check_buf(buf, fd);                               // проверка на наличие \n в буфере
        if (fd_list[fd] == NULL)
            fd_list[fd] = ft_lstnew(buf, BUFF_SIZE);
        else if (ret != 1 && lineR != 1)                          // если остался только \n для него уже не создаем лист и если лист не был создан в check_buf
            ft_lstadd(&(fd_list[fd]), ft_lstnew(buf, BUFF_SIZE)); // скопировали в узел списка из буфера часть строки
        ft_bzero(buf, BUFF_SIZE);                                 // очистили буфер
        printf("создан узел списка с адресом: %p\n", fd_list[fd]);
        printf("в нем: %s\n", fd_list[fd]->content);
        printf("указывает на: %p\n", fd_list[fd]->next);
        if (lineR == 1)                                           // если в буфере была \n, строка считана
            break;
    }

    if (ret == 0)
        return (0);
    else
        return (1);
}

int			get_next_line(const int fd, char **line)
{
    int ret;

    if (fd < 0)
        return (-1);
    ret = fromReadToList(fd);
    //if file - >   OPEN IT
    //if stdout - > fd == 1
    //if stdin - >  fd == 0

    //  *line = get_text_from_list_to_line(list, *line);
    //
    // add func for cleaning the list;
    return (ret);
}

int main()
{
    int fd = open("a", O_RDONLY);

    char *ptr = (char *)malloc(sizeof(*ptr) * 500);
    printf("ВЫЗОВ GNL ДЛЯ a...\n");
    get_next_line(fd, &ptr);
    //printf("vyzov GNL dlya b...\n");
    //get_next_line(open("b", O_RDONLY), &ptr);
    printf("ВЫЗОВ GNL ДЛЯ a... 2й раз\n");
    get_next_line(fd, &ptr);
    //printf("vyzov GNL dlya b...\n");
    //get_next_line(open("b", O_RDONLY), &ptr);
    //<===== CHECK =====>
    while(1)
    {
        printf("fd_list[fd].content = %s\n", fd_list[fd]->content);
        fd_list[fd] = fd_list[fd]->next;
        if (fd_list[fd] == NULL)
            break;
    }
    //<===== CHECK =====>
}
/*
 * На повестке дня:
 * 1) Чтобы работало с буфером размером 1, >7
 * С буфером больше 7, приставляет рандомный символ
 * The return value can be 1, 0 or -1 depending on whether a line has been read,
when the reading has been completed, or if an error has happened respectively.
 *
 * There cannot be a main function in your program.
• Do not push a Makefile.

 All heap allocated memory space must be properly freed when necessary.
• Your project cannot have memory leaks.
 */