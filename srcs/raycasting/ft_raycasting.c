/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:46:25 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/20 16:33:52 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void ft_raycasting(t_data data)
{
	int height_wall;
	t_ray ray_data;

	// printf("%d\n", data.pos_player[0]);
	// printf("%d\n", data.pos_player[1]);
	init_ray_data(data, &ray_data);
	ray_data = calculate_distance(data, ray_data);
	height_wall = data.resolution[1] / ray_data.dist;
	// printf("height_wall: %d\n", height_wall);
	// printf("ray_data.dist: %f\n", ray_data.dist);
}

void init_ray_data(t_data data, t_ray *ray_data)
{
	ray_data->map[0] = data.pos_player[0];
	ray_data->map[1] = data.pos_player[1];
	ray_data->is_hit = 0;
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
	}
	else if (data.pos_camera == 'E')
	{
		ray_data->dir[0] = 0;
		ray_data->dir[1] = 1;
	}
}



void display_column(int column, int size_wall)
{
	(void)column;
	(void)size_wall;
}