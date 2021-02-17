/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:58:45 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/17 15:33:45 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_struct(t_ray data, t_data data_map)
{
	printf("stepX: %d, stepY: %d\n", data.step[0], data.step[1]);
	printf("mapX: %d, mapY: %d\n", data.map[0], data.map[1]);
	printf("is_hit: %d\n", data.is_hit);
	printf("eucli_distX: %f, eucli_distY: %f\n", data.eucli_dist[0], data.eucli_dist[1]);
	printf("delta_distX: %f, delta_distY: %f\n", data.delta_dist[0], data.delta_dist[1]);
	printf("dist: %f\n", data.dist);
	printf("ray_dirX: %f, ray_dirY: %f\n", data.ray_dir[0], data.ray_dir[1]);
	printf("dirX: %f, dirY: %f\n", data.dir[0], data.dir[1]);
	printf("side: %d\n", data.side);
	printf("h_wall: %d\n", data.h_wall);
	printf("drawS: %d, drawE: %d\n", data.draw[0], data.draw[1]);
	printf("steptex: %f, wallx: %f\n", data.step_tex, data.wallx);
	printf("texx: %d, texy: %d, texpos: %f\n", data.texx, data.texy, data.texpos);
	printf("posPlayer[0]: %f, posPlayer[1]: %f\n", data_map.pos_player[0], data_map.pos_player[1]);
}

void	launch_minilibx(t_window window, t_tab ar_s)
{
	mlx_hook(window.mlx_win, 2, 0, ft_event_pressed, &ar_s);
	mlx_hook(window.mlx_win, 3, 0, ft_event_released, &ar_s);
	mlx_hook(window.mlx_win, 17, 0L, ft_close_window, &ar_s);
	mlx_loop_hook(window.mlx, ft_loop_hook, &ar_s);
	mlx_loop(window.mlx);
}

void	ft_init_general_main(t_tab *ar_s)
{
	fix_resolution_data(&ar_s->data, ar_s->window);
	ar_s->window.number_sprites = ft_count_sprite(ar_s->data);
	ar_s->window.sprite = ft_pick_sprite(ar_s->data,
						ar_s->window.number_sprites);
	ar_s->window.mlx = mlx_init();
	ar_s->window.mlx_win = mlx_new_window(ar_s->window.mlx,
						ar_s->data.resolution[0],
						ar_s->data.resolution[1], "CUB3D");
	init_ray_data_before(&ar_s->ray_data, ar_s->data);
	init_button(&ar_s->key);
}

int		main(int ac, char **av)
{
	int		fd;
	t_tab	ar_s;

	init_data(&ar_s.data);
	if (ac == 1)
		return (ft_error_msg(22, &ar_s.data));
	fd = open(av[1], O_RDWR);
	if (fd <= 0 || !ft_is_format(av[1], ".cub"))
		return (ft_error_msg(22, &ar_s.data));
	ft_parsing(fd, &ar_s.data);
	ft_init_general_main(&ar_s);
	if (ac >= 3)
	{
		if (ac == 3 && !ft_strcmp(av[2], "--save"))
			return(ft_bmp(&ar_s));
		else
			return (ft_error_msg(22, &ar_s.data));
	}
	ft_refresh_raycasting(&ar_s, 1);
	launch_minilibx(ar_s.window, ar_s);
	close(fd);
	free_struct(&ar_s.data);
	if (ar_s.window.sprite)
		free(ar_s.window.sprite);
	return (1);
}
