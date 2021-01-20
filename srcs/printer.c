/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:54:45 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/20 16:45:07 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_strs(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
		ft_printf("%s\n", strs[i++]);
}

void	ft_print_struct(t_ray data)
{
	int i;

	i = 0;
	printf("stepX: %d, stepY: %d\n", data.step[0], data.step[1]);
	printf("mapX: %d, mapY: %d\n", data.map[0], data.map[1]);
	printf("is_hit: %d\n", data.is_hit);
	printf("eucli_distX: %f, eucli_distY: %f\n", data.eucli_dist[0], data.eucli_dist[1]);
	printf("deltaDistX: %f, deltaDistY: %f\n", data.deltaDist[0], data.deltaDist[1]);
	printf("dist: %f\n", data.dist);
	printf("ray_dirX: %f, ray_dirY: %f\n", data.rayDir[0], data.rayDir[1]);
	printf("dirX: %d, dirY: %d\n", data.dir[0], data.dir[1]);
	printf("side: %d\n", data.side);
}
