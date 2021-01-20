/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:28:06 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/20 16:36:32 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

t_ray   calculate_distance(t_data data, t_ray ray_data)
{
	int i;

	i = -1;
	while (++i < data.resolution[1])
	{
		ray_data.rayDir[0] = ray_data.dir[0] + \
		(2 * i) / (data.resolution[1] - 1);
		ray_data.rayDir[1] = ray_data.dir[1] + 0.66 * \
		((2 * i) / (data.resolution[1] - 1));
		caculate_deltaDist(&ray_data);
		calculate_step_and_dist(data, &ray_data);
        if (ray_data.side)
            ray_data.dist = (ray_data.map[1] - data.pos_player[1] \
            + (1 - ray_data.step[1]) / 2) / ray_data.rayDir[1];
        else
            ray_data.dist = (ray_data.map[0] - data.pos_player[0] \
            + (1 - ray_data.step[0]) / 2) / ray_data.rayDir[0];
	}
    return (ray_data);
}

void    until_wall_is_hit(t_data data, t_ray *ray_data)
{
    while (!ray_data->is_hit)
    {
        if (ray_data->eucli_dist[0] < ray_data->eucli_dist[1])
        {
            ray_data->eucli_dist[0] += ray_data->deltaDist[0];
            ray_data->map[0] += ray_data->step[0];
            ray_data->side = 0;
        }
        else
        {
            ray_data->eucli_dist[1] += ray_data->deltaDist[1];
            ray_data->map[1] += ray_data->step[1];
            ray_data->side = 1;
        }
        if (data.map[ray_data->map[0]][ray_data->map[1]])
            ray_data->is_hit = 1;
    }
}

void calculate_step_and_dist(t_data data, t_ray *ray_data)
{
	int i;

	i = -1;
	while (++i != 2)
	{
		if (ray_data->rayDir[i] < 0)
		{
			ray_data->step[i] = -1;
			ray_data->eucli_dist[i] = (data.pos_player[i] - ray_data->map[i]) * \
			ray_data->deltaDist[i];
		}
		else
		{
			ray_data->step[i] = 1;
			ray_data->eucli_dist[i] = (ray_data->map[i] + 1.0 - data.pos_player[i]) \
            * ray_data->deltaDist[i];
		}	
	}

}

void    caculate_deltaDist(t_ray *ray_data)
{
	if (ray_data->rayDir[0] == 0)
		ray_data->deltaDist[0] = 0.0;
	else
		ray_data->deltaDist[0] = fabs(1 / ray_data->rayDir[0]);
	if (ray_data->rayDir[1] == 1)
		ray_data->deltaDist[1] = 0.0;
	else
		ray_data->deltaDist[1] = fabs(1 / ray_data->rayDir[1]);
    // printf("%f, %f ", ray_data->deltaDist[0], ray_data->deltaDist[1]);
    // printf("%f\n", ray_data->deltaDist[1]);
}
