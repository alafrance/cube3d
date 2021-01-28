/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:58:45 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/28 15:58:28 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	data->pos_player[0] = -1;
	data->pos_player[1] = -1;
	data->pos_camera = 0;
}

int main(int ac, char **av)
{
    t_data  data;
    int     fd;
	t_ray ray_data;
	t_window window;
	t_tab ar_s;

	init_data(&data);
    if (ac != 2)
         return (ft_error_msg(22, &data));
    fd = open(av[1], O_RDWR);
    if (fd <= 0 || !ft_is_format(av[1], ".cub"))
        return (ft_error_msg(22, &data));
    ft_parsing(fd, &data);
	ft_init_window(&window, data);
	init_ray_data_before(&ray_data, data);
	init_tab_ar_s(&ar_s, ray_data, data, window);
	ft_refresh_raycasting(&ar_s);
	mlx_hook(window.mlx_win, 2, 0, ft_event_pressed, &ar_s);
	mlx_hook(window.mlx_win, 3, 0, ft_event_released, &ar_s);
	mlx_hook(window.mlx_win, 17, 0L, ft_close_window, &ar_s);
	mlx_loop_hook(window.mlx, ft_loop_hook, &ar_s);
	mlx_loop(window.mlx);
	close(fd);
	free_struct(&data);
	return (1);
}