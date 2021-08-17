#include <unistd.h>
#include <stdlib.h>

int get_next_line(char** line)
{
    char buff;
    int i;

    i = 0;
    *line = malloc(8000);
    if (!*line)
        return (-1);
    while (read(0, &buff, 1))
    {
        if (buff == '\n')
        {
            (*line)[i] = '\0';
            return (1);
        }
        (*line)[i++] = buff;
    }
    (*line)[i] = '\0';
    return (0);
}