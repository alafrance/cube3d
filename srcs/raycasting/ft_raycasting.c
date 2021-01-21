/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:46:25 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/21 23:24:38 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_display_raycasting(t_data data)
{
	int column;
	int draw[2];
	t_ray ray_data;
	t_window window;

	column = -1;
	ft_init_window(&window, data);
	init_ray_data(data, &ray_data);
	data.pos_player[0] = 22;
	data.pos_player[1] = 12;
	while (++column < data.resolution[0])
	{
			ft_raycasting(data, &ray_data, column);
			// ft_print_struct(ray_data);
			draw[0] = -ray_data.h_wall / 2 + data.resolution[1] / 2;
			if (draw[0] < 0)
				draw[0] = 0;
			draw[1] = ray_data.h_wall / 2 + data.resolution[1] / 2;
			if (draw[1] >= data.resolution[1])
				draw[1] = data.resolution[1] - 1;
			ft_display_column(window, draw, column);
	}
	mlx_put_image_to_window(window.mlx, window.mlx_win, window.img.img, 0, 0);
    mlx_loop(window.mlx);
}

void	ft_raycasting(t_data data, t_ray *ray_data, int i)
{
	*ray_data = calculate_distance(data, *ray_data, i);
	if (ray_data->dist == 0)
		ray_data->h_wall = 0;
	else
		ray_data->h_wall = (int)(data.resolution[1] / (int)ray_data->dist);
}

void init_ray_data(t_data data, t_ray *ray_data)
{
	ray_data->map[0] = data.pos_player[0];
	ray_data->map[1] = data.pos_player[1];
	ray_data->is_hit = 0;
	ray_data->side = 0;
	ray_data->dist = 0;
	ray_data->plane[0] = 0;
	ray_data->plane[1] = 0.66;
	ray_data->dir[0] = -1;
	ray_data->dir[1] = 0;	
}
