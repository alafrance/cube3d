/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:54:25 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/24 18:21:44 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void move_up(t_tab ar_s, int moveSpeed)
// {
// 	int afterPosX1;
// 	int afterPosY1;
// 	int afterPosX2;
// 	int afterPosY2;

// 	afterPosX1 = ar_s.data->pos_player[0] + (int)ar_s.ray_data->dir[0] * moveSpeed;
// 	afterPosY1 = ar_s.data->pos_player[1];
// 	afterPosX2 = ar_s.data->pos_player[0];
// 	afterPosY2 = ar_s.data->pos_player[1] + (int)ar_s.ray_data->dir[1] * moveSpeed;

// 	printf("afterPOS, X1: %d, Y1: %d, X2: %d, Y2: %d\n", afterPosX1, afterPosY1, afterPosX2, afterPosY2);
// 	// if (ar_s.data->map[afterPosX1][afterPosY1] != '1')
// 		// ar_s.data->pos_player[0] += ar_s.ray_data->dir[0] * moveSpeed;
// 	// if (ar_s.data->map[afterPosX1][afterPosY2] != '1')
// 		// ar_s.data->pos_player[1] += ar_s.ray_data->dir[1] * moveSpeed;
// 	printf("pos_player[0]: %d\n", ar_s.data->pos_player[0]);
// 	printf("pos_player[1]: %d\n", ar_s.data->pos_player[1]);
// }
// void move_down(t_tab ar_s, int moveSpeed)
// {
// 	(void)ar_s;
// 	(void)moveSpeed;
// 	printf("down\n");
// }

int	ft_move_camera(int keycode, t_tab ar_s)
{
	if (keycode == 126)
	{
		printf("posX: %d, dirX: %d, posY: %d, dirY: %d\n", *(ar_s.posX), (int)ar_s.ray_data->dir[0], *ar_s.posY, (int)ar_s.ray_data->dir[1]);
		// move_up(ar_s, 1);	
	}
	else if (keycode == 125)
		printf("down\n");
		// move_down(ar_s, 1);
	else if (keycode == 124)
	{
		printf("right\n");
	}
	else if (keycode == 123)
	{
		printf("left\n");
	}
	return (1);
}
// 126 = UP
// 125 = DOWN
// 124 = RIGHT
// 125 = LEFT