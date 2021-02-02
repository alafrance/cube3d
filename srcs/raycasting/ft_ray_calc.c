/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:28:06 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/02 17:11:54 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	calculate_distance(t_data data, t_ray ray_data, int i)
{
	double cameraX;

	cameraX = 2 * i / (double)data.resolution[0] - 1;
	ray_data.rayDir[0] = ray_data.dir[0] + ray_data.plane[0] * cameraX;
	ray_data.rayDir[1] = ray_data.dir[1] + ray_data.plane[1] * cameraX;
	ray_data.deltaDist[0] = (ray_data.rayDir[1] == 0) ? 0 :
							((ray_data.rayDir[0] == 0) ? 1 : 
							fabs(1 / ray_data.rayDir[0]));
	ray_data.deltaDist[1] = (ray_data.rayDir[0] == 0) ? 0 :
							((ray_data.rayDir[1] == 0) ? 1 :
							fabs(1 / ray_data.rayDir[1]));
	init_step_and_eucli_dist(data, &ray_data);
	until_wall_is_hit(data, &ray_data);
	if (ray_data.side == 0)
	{
		ray_data.dist = (ray_data.map[0] - data.pos_player[0] + 
						(1 - ray_data.step[0]) / 2) / ray_data.rayDir[0];
	}
	else
	{
		ray_data.dist = (ray_data.map[1] - data.pos_player[1] + 
						(1 - ray_data.step[1]) / 2) / ray_data.rayDir[1];
		
	}
	return (ray_data);
}

void init_step_and_eucli_dist(t_data data, t_ray *ray_data)
{
	int i;

	i = -1;

	while (++i != 2)
	{
		if (ray_data->rayDir[i] < 0)
		{
			
			ray_data->step[i] = -1;
			ray_data->eucli_dist[i] = (data.pos_player[i] - ray_data->map[i]) * ray_data->deltaDist[i];
		}
		else
		{
			ray_data->step[i] = 1;
			ray_data->eucli_dist[i] = (ray_data->map[i] + 1.0 
									- data.pos_player[i]) * ray_data->deltaDist[i];
		}
	}
}

void	increment_eucli_dist_map(t_ray *ray_data, int i)
{
	ray_data->eucli_dist[i] += ray_data->deltaDist[i];
	ray_data->map[i] += ray_data->step[i];
	ray_data->side = i;
}

void	until_wall_is_hit(t_data data, t_ray *ray_data)
{
	while (ray_data->is_hit == 0)
	{
		if (ray_data->eucli_dist[0] < ray_data->eucli_dist[1])
			increment_eucli_dist_map(ray_data, 0);
		else
			increment_eucli_dist_map(ray_data, 1);
		if (data.map[ray_data->map[0]][ray_data->map[1]] == '1')
			ray_data->is_hit = 1;
	}
}

void	ft_calculate_texture(t_ray *ray_data, t_img texture, t_data data)
{
	if (ray_data->side)
		ray_data->wallx = data.pos_player[0] + ray_data->dist * ray_data->rayDir[0];
	else
		ray_data->wallx = data.pos_player[1] + ray_data->dist * ray_data->rayDir[1];
	ray_data->wallx -= floor(ray_data->wallx);
	ray_data->texx = (int)(ray_data->wallx * (double)texture.width);
	if ((ray_data->side && ray_data->rayDir[1] < 0) || (!ray_data->side && ray_data->rayDir[0] > 0))
		ray_data->texx = texture.width - ray_data->texx - 1;
	ray_data->step_tex = (double)texture.height / ray_data->h_wall;
	ray_data->texpos = (ray_data->draw[0] - data.resolution[1] / 2 + ray_data->h_wall / 2) * ray_data->step_tex;
}