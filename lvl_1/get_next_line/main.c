#include "get_next_line.h"

int main(int ac, char **av) {
        int fd = 0;

        if (ac >= 2) {
                fd = open(av[1], O_RDONLY);
        }
        int ret = 0;
        char *line = NULL;
        while ((ret = get_next_line(fd, &line)) > 0) 
		{
            printf("{%d}%s\n", ret, line);
        }
        get_next_line(0, &line);
            printf("{%d}%s\n", ret, line);

}