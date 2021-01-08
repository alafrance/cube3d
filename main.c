#include "cub3d.h"

int main()
{
    char *line;

    line = NULL;
    get_next_line(open("map.cub", O_RDONLY), &line);
    ft_printf("line %s\n", line);
}