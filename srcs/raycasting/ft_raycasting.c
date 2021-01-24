/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:46:25 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/24 18:20:45 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void ft_display_raycasting(t_data data)
{
	t_ray ray_data;
	t_window window;
	t_tab ar_s;

	while (1 == 1)
	{
		ft_init_window(&window, data);
		ft_raycasting(data, &ray_data, window);
		mlx_put_image_to_window(window.mlx, window.mlx_win, window.img.img, 0, 0);
		ar_s.ray_data = &ray_data;
		ar_s.posX = &data.pos_player[0];
		ar_s.posY = &data.pos_player[1];
		ar_s.map = data.map;
		mlx_hook(window.mlx_win, 2, 1L<<0, ft_move_camera, &ar_s);
		mlx_loop(window.mlx);
	}
}

void	ft_raycasting(t_data data, t_ray *ray_data, t_window window)
{
	int column;

	column = -1;
	init_ray_data_before(ray_data);
	while (++column < data.resolution[0])
	{
		init_ray_data_after(data, ray_data);
		*ray_data = calculate_distance(data, *ray_data, column);
		if (ray_data->dist == 0)
			ray_data->h_wall = 0;
		else
			ray_data->h_wall = (int)(data.resolution[1] / (int)ray_data->dist);
		ray_data->draw[0] = -ray_data->h_wall / 2 + data.resolution[1] / 2;
		if (ray_data->draw[0] < 0)
			ray_data->draw[0] = 0;
		ray_data->draw[1] = ray_data->h_wall / 2 + data.resolution[1] / 2;
		if (ray_data->draw[1] >= data.resolution[1])
			ray_data->draw[1] = data.resolution[1] - 1;
		ft_display_column(window, *ray_data, data, column);
	}
}

void init_ray_data_before(t_ray *ray_data)
{
	ray_data->plane[0] = 0;
	ray_data->plane[1] = 0.66;
	ray_data->dir[0] = -1;
	ray_data->dir[1] = 0;	
}

void init_ray_data_after(t_data data, t_ray *ray_data)
{
	ray_data->map[0] = data.pos_player[0];
	ray_data->map[1] = data.pos_player[1];
	ray_data->is_hit = 0;
	ray_data->plane[0] = 0;
	ray_data->plane[1] = 0.66;
	ray_data->dir[0] = -1;
	ray_data->dir[1] = 0;	
}
