/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:54:25 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/26 17:22:23 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(t_tab *ar_s, int afterPosX, int afterPosY)
{
	if (ar_s->data.map[afterPosX][ar_s->data.pos_player[1]] == '0')
		ar_s->data.pos_player[0] = afterPosX;
	if (ar_s->data.map[ar_s->data.pos_player[0]][afterPosY] == '0')
		ar_s->data.pos_player[1] = afterPosY;
}

void	ft_move_up(t_tab *ar_s, double moveSpeed)
{
	int afterPosX;
	int	afterPosY;

	afterPosX = ar_s->data.pos_player[0] + ar_s->ray_data.dir[0]
					* moveSpeed;
	afterPosY = ar_s->data.pos_player[1] + ar_s->ray_data.dir[1]
					* moveSpeed;
	ft_move(ar_s, afterPosX, afterPosY);
}

void	ft_move_down(t_tab	*ar_s, double moveSpeed)
{
	int afterPosX;
	int afterPosY;

	printf("before: %d ", ar_s->data.pos_player[0]);
	printf("%d\n", ar_s->data.pos_player[1]);
	afterPosX = ar_s->data.pos_player[0] - (int)ar_s->ray_data.dir[0]
					* moveSpeed;
	afterPosY = ar_s->data.pos_player[1] - (int)ar_s->ray_data.dir[1]
					* moveSpeed;
	ft_move(ar_s, afterPosX, afterPosY);
	printf("before: %d ", ar_s->data.pos_player[0]);
	printf("%d\n", ar_s->data.pos_player[1]);
}
