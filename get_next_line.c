#include "get_next_line.h"

static char *fd_list[OPEN_MAX];

int        str_and_fd(char *ptr, char **line, int fd)
{
    size_t i;
    char *strcpy;
    //ptr = сохранненая в fd_list часть строки или буфер с новой строкой
    //strcpy = (char *)malloc(sizeof(char) * ft_strlen(ptr));
    strcpy = ft_strdup(ptr);
    printf("line adr after strdup= %p\n", strcpy);
    i = 0;
    printf("str_and_fd: strcpy = %s, strcpy address = %p\nline = %s, line address = %p */\n", strcpy, strcpy, *line, *line);
    while (i < BUFF_SIZE && strcpy[i] != '\n' && strcpy[i])
        i++;
    if (!(**line))
    {
        *line = ft_strsub(strcpy, 0, i); // кладем все до новой строки включительно
        printf("line created: %s\n", *line);
    }
    else {                                      // дополняем если в буфере поместилось меньше, чем строка до \n
        *line = ft_strjoin(*line, ft_strsub(strcpy, 0, i));
        printf("line joined: %s\n", *line);
    }
    if (strcpy[i] == '\n' && strcpy[i + 1] != '\0') {
        free(fd_list[fd]);
        fd_list[fd] = ft_strdup(&(strcpy[i + 1])); // оставляем в fd_list хранить все, что после новой строки
        ft_memdel((void **)&strcpy);
        return (1);
    }
    ft_memdel((void **)&strcpy);
    return (0);
}

int			get_next_line(const int fd, char **line)
{
    int ret;
    char buf[BUFF_SIZE + 1];

    ret = 0;
    if (fd < 0)
        return (-1);
    if (fd_list[fd]) // если огрызок есть, сначала читаем его
    {
        printf("substring detected! = %s, it's address = %p, line = %s, line address = %p\n", fd_list[fd], &fd_list[fd], *line, *line);
        ret = str_and_fd(fd_list[fd], line, fd); // если вернули 1, то считали строку
        if (ret)                    // в огрызке была новая строка - считали, можно выходить
            return (1);
        // далее идем если (1)огрызка не было или (2)в нем не было новой строки
    }
    while ((ret = read(fd, buf, BUFF_SIZE))) // считали из файла в массив buf кол-во бафсайз (или меньше, если строка закончилась)
    {
        if (ret == -1)
            return (ret);
        // теперь нужно проверить есть ли уже начало строки (могли туда закинуть из огрызка)
        buf[BUFF_SIZE] = '\0';
        ret = str_and_fd(buf, line, fd);
        // если в буфере была новая строка, вернем 1
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