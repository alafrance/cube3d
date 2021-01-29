/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:46:25 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/29 16:02:07 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_refresh_raycasting(t_tab *ar_struct)
{
	mlx_clear_window(ar_struct->window.mlx, ar_struct->window.mlx_win);
	ft_raycasting(ar_struct->data, &ar_struct->ray_data, ar_struct->window);
	mlx_put_image_to_window(ar_struct->window.mlx, ar_struct->window.mlx_win, ar_struct->window.img.img, 0, 0);
}

void	ft_raycasting(t_data data, t_ray *ray_data, t_window window)
{
	int column;

	column = -1;
	// while (++column < data.resolution[0])
	// {
		init_ray_data_after(data, ray_data);
		*ray_data = calculate_distance(data, *ray_data, column);
		if ((int)ray_data->dist == 0)
			ray_data->h_wall = (int)data.resolution[1];
		else
			ray_data->h_wall = (int)(data.resolution[1] / ray_data->dist);
		ray_data->draw[0] = -ray_data->h_wall / 2 + data.resolution[1] / 2;
		ft_calculate_texture(data, ray_data, window.texture);
		ft_display_column(window, *ray_data, data, column);
	// }
	ft_print_struct(*ray_data);
}


void	init_ray_data_before(t_ray *ray_data, t_data data)
{
	data.map[(int)data.pos_player[0]][(int)data.pos_player[1]] = '0';
	ray_data->plane[0] = 0;
	ray_data->plane[1] = 0.66;
	if (data.pos_camera == 'N')
	{
		ray_data->dir[0] = -1;
		ray_data->dir[1] = 0;
	}
	else if (data.pos_camera == 'S')
	{
		ray_data->dir[0] = 1;
		ray_data->dir[1] = 0;
	}
	else if (data.pos_camera == 'W')
	{
		ray_data->dir[0] = 0;
		ray_data->dir[1] = -1;
		ray_data->plane[0] = -0.66;
		ray_data->plane[1] = 0;
		
	}
	else if (data.pos_camera == 'E')
	{
		ray_data->dir[0] = 0;
		ray_data->dir[1] = 1;
		ray_data->plane[0] = 0.66;
		ray_data->plane[1] = 0;
	}
}

void	init_ray_data_after(t_data data, t_ray *ray_data)
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