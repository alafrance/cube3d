/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:03:22 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/06 12:57:10 by alafranc         ###   ########lyon.fr   */
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

void	fix_resolution_data(t_data *data, t_window window)
{
	int width_max;
	int height_max;

	mlx_get_screen_size(window.mlx, &width_max, &height_max);
	data->resolution[0] = closest_multiple_of_x(data->resolution[0], 320);
	data->resolution[1] = closest_multiple_of_x(data->resolution[1], 320);
	if (data->resolution[0] > width_max)
		data->resolution[0] = width_max;
	if (data->resolution[1] > height_max)
		data->resolution[1] = height_max;
}

void	init_ray_data_after(t_data data, t_ray *ray_data)
{
	ray_data->map[0] = data.pos_player[0];
	ray_data->map[1] = data.pos_player[1];
	ray_data->is_hit = 0;
}

void	init_ray_data_before(t_ray *ray_data, t_data data)
{
	data.map[(int)data.pos_player[0]][(int)data.pos_player[1]] = '0';
	if (data.pos_camera == 'N')
	{
		ray_data->dir[0] = -1;
		ray_data->dir[1] = 0;
		ray_data->plane[0] = 0;
		ray_data->plane[1] = 0.66;
	}
	else if (data.pos_camera == 'S')
	{
		ray_data->dir[0] = 1;
		ray_data->dir[1] = 0;
		ray_data->plane[0] = 0;
		ray_data->plane[1] = -0.66;
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

void init_button(t_key *key)
{
	key->key_a = 0;
	key->key_s = 0;
	key->key_d = 0;
	key->key_w = 0;
	key->key_up = 0;
	key->key_down = 0;
	key->key_left = 0;
	key->key_right = 0;
}