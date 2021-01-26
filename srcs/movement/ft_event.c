/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:23:23 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/26 16:24:57 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_event_pressed(int keycode, t_tab *ar_s)
{
	if (keycode == 0)
		ar_s->key_pressed = 0;
	else if (keycode == 1)
		ar_s->key_pressed = 1;
	else if (keycode == 2)
		ar_s->key_pressed = 2;
	else if (keycode == 13)
		ar_s->key_pressed = 3;
	else if (keycode == 53)
		ft_close_window(ar_s);
	else
		return (0);
	printf("pressed\n");
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
	void	(*ft_movement[4])(t_tab *, double);
	double	moveSpeed;

	moveSpeed = 0.1;
	ft_movement[0] = &ft_rotate_right;
	ft_movement[1] = &ft_move_down;
	ft_movement[2] = &ft_rotate_left;
	ft_movement[3] = &ft_move_up;
	if (ar_s->is_pressed)
	{
		ft_movement[ar_s->key_pressed](ar_s, moveSpeed);
		// mlx_clear_window(ar_s->window.mlx, ar_s->window.mlx_win);
		// ft_print_struct(ar_s->ray_data);
		ft_raycasting(ar_s->data, &ar_s->ray_data, ar_s->window);
		mlx_put_image_to_window(ar_s->window.mlx, ar_s->window.mlx_win
								, ar_s->window.img.img, 0, 0);
	}
	return (1);
}