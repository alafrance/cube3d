/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:08:42 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/03 13:41:52 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate_left(t_tab *ar_s, double rotSpeed)
{
	ft_rotate(ar_s, -rotSpeed);
}

void	ft_rotate_right(t_tab *ar_s, double rotSpeed)
{
	ft_rotate(ar_s, rotSpeed);
}

void	ft_rotate(t_tab *ar_s, double  rotSpeed)
{
	double oldDir = ar_s->ray_data.dir[0];

    ar_s->ray_data.dir[0] =  ar_s->ray_data.dir[0] * cos(rotSpeed) -  ar_s->ray_data.dir[1] * sin(rotSpeed);
	ar_s->ray_data.dir[1] = oldDir * sin(rotSpeed) + ar_s->ray_data.dir[1] * cos(rotSpeed);
	ar_s->ray_data.plane[0] = ar_s->ray_data.dir[1] * 0.66;
	ar_s->ray_data.plane[1] = -ar_s->ray_data.dir[0] * 0.66;
	ft_refresh_raycasting(ar_s);
}