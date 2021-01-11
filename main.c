#include "cub3d.h"

int main(int ac, char **av)
{
    t_data  data;
    int     fd;

    if (ac != 2)
         return (0);
    fd = open(av[1], O_RDONLY);
    if (fd <= 0)
        return (ft_print_error("No such file or directory\n"));
    if (!(ft_parsing(fd, &data)))
        return (0);
    if (!ft_map_is_valid(data))
        return (0);
    ft_printf("EVERYTHING IS FINE\n");
}