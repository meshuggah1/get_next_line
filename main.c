#include <stdio.h>
#include "get_next_line.h"
int main()
{
    int fd = open("a", O_RDONLY);
    char *line;
    int i = 1;

    while (get_next_line(fd, &line) > 0)
    {
        printf("in main %d ", i++);
        printf("%s\n", line);
        ft_memdel((void **)&line);
    }
    //printf("%d ", i++);
    //printf("%s\n", line);
    ft_memdel((void **) &line);
    return (0);
}
//    int fd1 = open("b", O_RDONLY);
//
//    printf("ВЫЗОВ GNL ДЛЯ a...\n");
//    get_next_line(fd, &ptr);
//    printf("ptr = %s\n", ptr);
//    printf("vyzov GNL dlya b...\n");
//    get_next_line(fd1, &ptr);
//    printf("ВЫЗОВ GNL ДЛЯ a... 2й раз\n");
//    get_next_line(fd, &ptr);
//    printf("vyzov GNL dlya b...\n");
//    get_next_line(fd1, &ptr);
//    printf("ptr = %s\n", ptr);
//
//    printf("ВЫЗОВ GNL ДЛЯ a... 3й раз\n");
//    get_next_line(fd, &ptr);
//    printf("ptr = %s\n", ptr);
//    printf("OPEN_MAX FOR DOVRANI4 = %d\n", OPEN_MAX);