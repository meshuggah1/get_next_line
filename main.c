#include "get_next_line.h"
# include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("a", O_RDONLY);

    char **line;
    int gnl;

    line = (char **)malloc(sizeof(char *));
    //*line = (char *)malloc(sizeof(char));

    //line = NULL;

    while ((gnl = get_next_line(fd, line)) > 0)
    {
        printf("%d ", gnl);
        printf("%s\n", *line);
        //printf("len = %d\n", strcmp(line, "123"));
        //free(line);
    }
    printf("%d ", gnl);
    //printf("%s\n", *line);
    //free(*line);
    return (0);
}