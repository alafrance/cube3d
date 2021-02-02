/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:54:25 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/02 17:44:54 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(t_tab *ar_s, double afterPosX, double afterPosY)
{
	if (ar_s->data.map[(int)afterPosX][(int)ar_s->data.pos_player[1] + 1] != '1')
		ar_s->data.pos_player[0] = afterPosX;
	if (ar_s->data.map[(int)ar_s->data.pos_player[0]][(int)afterPosY] != '1')
		ar_s->data.pos_player[1] = afterPosY;
}

void	ft_move_up(t_tab *ar_s, double moveSpeed)
{
	double afterPosX;
	double	afterPosY;

	afterPosX = ar_s->data.pos_player[0] + ar_s->ray_data.dir[0]
					* moveSpeed;
	afterPosY = ar_s->data.pos_player[1] + ar_s->ray_data.dir[1]
					* moveSpeed;
	ft_move(ar_s, afterPosX, afterPosY);
	
}

void	ft_move_down(t_tab	*ar_s, double moveSpeed)
{
	double afterPosX;
	double afterPosY;

	afterPosX = ar_s->data.pos_player[0] - ar_s->ray_data.dir[0]
					* moveSpeed;
	afterPosY = ar_s->data.pos_player[1] - ar_s->ray_data.dir[1]
					* moveSpeed;
	ft_move(ar_s, afterPosX, afterPosY);
}

void	ft_move_right(t_tab *ar_s, double moveSpeed)
{
	double afterPosX;
	double	afterPosY;
	afterPosX = ar_s->data.pos_player[0] - ar_s->ray_data.dir[1]
					* moveSpeed;
	afterPosY = ar_s->data.pos_player[1] + ar_s->ray_data.dir[0]
					* moveSpeed;
	ft_move(ar_s, afterPosX, afterPosY);
	
}

void	ft_move_left(t_tab	*ar_s, double moveSpeed)
{
	double afterPosX;
	double afterPosY;

	afterPosX = ar_s->data.pos_player[0] + ar_s->ray_data.dir[1]
					* moveSpeed;
	afterPosY = ar_s->data.pos_player[1] - ar_s->ray_data.dir[0]
					* moveSpeed;
	ft_move(ar_s, afterPosX, afterPosY);
}
