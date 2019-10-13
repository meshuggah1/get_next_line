#include "get_next_line.h"

static char *fd_list[OPEN_MAX];

int        str_and_fd(char *ptr, char **line, int fd)
{
    size_t i;
    char *strcpy;

    strcpy = (char *)malloc(sizeof(char) * ft_strlen(ptr));
    strcpy = ft_strcpy(strcpy, ptr);
    i = 0;
    //printf("str_and_fd: strcpy = %s, line = %s\n", strcpy, *line);
    while (i < BUFF_SIZE && strcpy[i] != '\n')
        i++;
    if (!(**line))
        *line = ft_strsub(strcpy, 0, i ); // кладем все до новой строки включительно
    else
        *line = ft_strjoin(*line, ft_strsub(strcpy, 0, i));
    if (strcpy[i] == '\n')
    {
        fd_list[fd] = &strcpy[i + 1]; // оставляем в fd_list хранить все, что после новой строки
        return (1);
    }
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
        //printf("огрызок на месте! = %s по адресу %p\n", fd_list[fd], &fd_list[fd]);
        ret = str_and_fd(fd_list[fd], line, fd); // если вернули 1, то считали строку
        if (ret)                    // в огрызке была новая строка - считали, можно выходить
            return (1);
    }
    // далее идем если (1)огрызка не было или (2)в нем не было новой строки

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
int main()
{
    int fd = open("a", O_RDONLY);
    int fd1 = open("b", O_RDONLY);

    char *ptr = (char *)malloc(sizeof(*ptr) * 500);
    printf("ВЫЗОВ GNL ДЛЯ a...\n");
    get_next_line(fd, &ptr);
    printf("ptr = %s\n", ptr);
    printf("vyzov GNL dlya b...\n");
    get_next_line(fd1, &ptr);
    printf("ВЫЗОВ GNL ДЛЯ a... 2й раз\n");
    get_next_line(fd, &ptr);
    printf("vyzov GNL dlya b...\n");
    get_next_line(fd1, &ptr);
    printf("ptr = %s\n", ptr);

    printf("ВЫЗОВ GNL ДЛЯ a... 3й раз\n");
    get_next_line(fd, &ptr);
    printf("ptr = %s\n", ptr);

}*/
/*
 * The return value can be 1, 0 or -1 depending on whether a line has been read,
when the reading has been completed, or if an error has happened respectively.
 *
 * There cannot be a main function in your program.
• Do not push a Makefile.
 All heap allocated memory space must be properly freed when necessary.
• Your project cannot have memory leaks.
 */