#include "cub3d.h"

void	init_data(t_data *data)
{
	data->resolution[0] = 0;
	data->resolution[1] = 0;
	data->path_ntexture = NULL;
	data->path_stexture = NULL;
	data->path_wtexture = NULL;
	data->path_etexture = NULL;
	data->path_sprite = NULL;
	data->map = NULL;
	data->color_floor = NULL;
	data->color_roof = NULL;
}


int main(int ac, char **av)
{
    t_data  data;
    int     fd;

	init_data(&data);
    if (ac != 2)
         return (0);
    fd = open(av[1], O_RDONLY);
    if (fd <= 0 || !filename_format_is_valid(av[1]))
        return (ft_error_msg(22, &data));
    if (!(ft_parsing(fd, &data)) || !ft_map_is_valid(data))
        return (0);
    ft_printf("EVERYTHING IS FINE\n");
}