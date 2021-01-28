/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:23:23 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/28 17:04:56 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	ft_event_pressed(int keycode, t_tab *ar_s)
{
	if (keycode == KEY_W)
		ar_s->key_pressed = KEY_W;
	else if (keycode == KEY_S)
		ar_s->key_pressed = KEY_S;
	else if (keycode == KEY_A)
		ar_s->key_pressed = KEY_A;
	else if (keycode == KEY_D)
		ar_s->key_pressed = KEY_D;
	else if (keycode == KEY_UP)
		ar_s->key_pressed = KEY_UP;
	else if (keycode == KEY_DOWN)
		ar_s->key_pressed = KEY_DOWN;
	else if (keycode == KEY_LEFT)
		ar_s->key_pressed = KEY_LEFT;
	else if (keycode == KEY_RIGHT)
		ar_s->key_pressed = KEY_RIGHT;
	else if (keycode == 53)
		ft_close_window(ar_s);
	else
		return (0);
	ar_s->is_pressed = 1;
	return (1);
}

int		ft_event_released(int keycode, t_tab *ar_s)
{
	if (keycode == ar_s->key_pressed || (keycode == 13 && ar_s->key_pressed == 3))
	{
		ar_s->is_pressed = 0;
		ar_s->key_pressed = -1;
	}
	return (0);
}

int ft_loop_hook(t_tab *ar_s)
{
	double	moveSpeed;

	moveSpeed = 0.05;
	if (ar_s->is_pressed)
	{
		if	(ar_s->key_pressed == KEY_W)
			ft_move_up(ar_s, moveSpeed);
		if	(ar_s->key_pressed == KEY_S)
			ft_move_down(ar_s, moveSpeed);
		if	(ar_s->key_pressed == KEY_D)
			ft_move_left(ar_s, moveSpeed);
		if	(ar_s->key_pressed == KEY_A)
			ft_move_right(ar_s, moveSpeed);
		if	(ar_s->key_pressed == KEY_LEFT)
			ft_rotate_left(ar_s, moveSpeed);
		if	(ar_s->key_pressed == KEY_RIGHT)
			ft_rotate_right(ar_s, moveSpeed);			
		ft_refresh_raycasting(ar_s);
	}
	return (1);
}