/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:46:25 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/26 16:08:47 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_display_raycasting(t_data data)
{
	t_ray ray_data;
	t_window window;
	t_tab ar_s;

	ft_init_window(&window, data);
	ft_raycasting(data, &ray_data, window);
	mlx_put_image_to_window(window.mlx, window.mlx_win, window.img.img, 0, 0);
	init_tab_ar_s(&ar_s, ray_data, data, window);
	mlx_hook(window.mlx_win, 2, 1L<<0, ft_event_pressed, &ar_s);
	mlx_hook(window.mlx_win, 3, 1L<<1, ft_event_released, &ar_s);
	mlx_hook(window.mlx_win, 17, 0L, ft_close_window, &ar_s);
	mlx_loop_hook(window.mlx, ft_loop_hook, &ar_s);
	mlx_loop(window.mlx);
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
}

void	init_tab_ar_s(t_tab *ar_s, t_ray ray_data, t_data data, t_window window)
{
	ar_s->ray_data = ray_data;
	ar_s->data = data;
	ar_s->window = window;
	ar_s->is_pressed = 0;
	ar_s->key_pressed = -1;
}