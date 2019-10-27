#include "get_next_line.h"

int        str_and_fd(char *ptr, char **line, char **o)
{
    size_t i;
    char *strcpy;

    //ptr = сохранненая в fd_list часть строки или буфер с новой строкой
    //strcpy = (char *)malloc(sizeof(char) * ft_strlen(ptr));
    strcpy = ft_strdup(ptr);
    i = 0;
    while (i < BUFF_SIZE && strcpy[i] != '\n' && strcpy[i])
        i++;
    if (!*line || !(**line))
        *line = ft_strsub(strcpy, 0, i); // кладем все до новой строки (или конца буфера) включительно
    else
        *line = ft_strjoin(*line, ft_strsub(strcpy, 0, i));  // дополняем если в буфере поместилось меньше, чем строка до \n
    if (strcpy[i + 1] == '\0')
        ft_memdel((void**)o);
    if (strcpy[i] == '\n')
    {
        if (strcpy[i + 1] != '\0')
            *o = ft_strdup(&(strcpy[i + 1])); // оставляем в fd_list хранить все, что после новой строки
        ft_memdel( (void **) &strcpy );
        return (1);
    }
    // else if ()
    ft_memdel((void **)&strcpy);
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
    if (*line && **line)
        ft_bzero(*line, ft_strlen(*line));
    if (f_list[fd]) // если огрызок есть, сначала читаем его
    {
        ret = str_and_fd(f_list[fd], line, &f_list[fd]); // если вернули 1, то считали строку
        if (ret)                    // в огрызке была новая строка - считали, можно выходить
            return (1);
        // далее идем если (1)огрызка не было или (2)в нем не было новой строки
    }
    while ((ret = read(fd, buf, BUFF_SIZE))) // считали из файла в массив buf кол-во бафсайз (или меньше, если строка закончилась)
    {
        if (ret == -1)
            return (ret);
        buf[ret] = '\0';
        ret = str_and_fd(buf, line, &f_list[fd]);
        ft_bzero(buf, BUFF_SIZE);
        if (ret == 1)
            break;
    }
    return (**line ? 1 : 0);
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