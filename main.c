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
	data->pos_player[0] = 0;
	data->pos_player[1] = 0;
}


int main(int ac, char **av)
{
    t_data  data;
    int     fd;

	init_data(&data);
    if (ac != 2)
         return (0);
    fd = open(av[1], O_RDWR);
    if (fd <= 0 || !ft_is_format(av[1], ".cub"))
        return (ft_error_msg(22, &data));
    if (!(ft_parsing(fd, &data)))
        return (0);
    ft_printf("EVERYTHING IS FINE\n");
	close(fd);
	ft_print_struct(data);
	return (1);
}