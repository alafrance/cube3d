/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:54:25 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/25 14:28:01 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void move(t_tab *ar_s, int moveSpeed, char op)
{
	int afterPos1[2];
	int afterPos2[2];

	afterPos1[1] = ar_s->data.pos_player[1];
	afterPos2[0] = ar_s->data.pos_player[0];
	if (op == '+')
	{
		afterPos1[0] = ar_s->data.pos_player[0] + (int)ar_s->ray_data.dir[0]
						* moveSpeed;
		afterPos2[0] = ar_s->data.pos_player[0];
		afterPos2[1] = ar_s->data.pos_player[1] + (int)ar_s->ray_data.dir[1]
						* moveSpeed;
	}
	else if (op == '-')
	{
		afterPos1[0] = ar_s->data.pos_player[0] - (int)ar_s->ray_data.dir[0]
						* moveSpeed;
		afterPos1[1] = ar_s->data.pos_player[1];
		afterPos2[1] = ar_s->data.pos_player[1] - (int)ar_s->ray_data.dir[1]
						* moveSpeed;
	}
	else
		return ;
	if (ar_s->data.map[afterPos1[0]][afterPos1[0]] != '1')
		ar_s->data.pos_player[0] = afterPos1[0];
	if (ar_s->data.map[afterPos2[1]][afterPos2[1]] != '1')
		ar_s->data.pos_player[1] = afterPos2[1];
}

void	rotate(t_tab *ar_s, int rotSpeed)
{
	double oldDir = ar_s->ray_data.dir[0];
    double oldPlane = ar_s->ray_data.plane[0];
	
    ar_s->ray_data.dir[0] =  ar_s->ray_data.dir[0] * cos(rotSpeed) -  ar_s->ray_data.dir[1] * sin(rotSpeed);
	ar_s->ray_data.dir[1] = oldDir * sin(rotSpeed) + ar_s->ray_data.dir[1] * cos(rotSpeed);
	ar_s->ray_data.plane[0] = ar_s->ray_data.plane[0] * cos(rotSpeed) - ar_s->ray_data.plane[1] * sin(rotSpeed);
	ar_s->ray_data.plane[1] = oldPlane * sin(rotSpeed) + ar_s->ray_data.plane[1] * cos(rotSpeed);
}