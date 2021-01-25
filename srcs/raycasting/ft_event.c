/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:23:23 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/25 17:00:15 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_event_pressed(int keycode, t_tab *ar_s)
{
	int moveSpeed;

	moveSpeed = 1;
	ar_s->is_pressed = 1;
	while (ar_s->is_pressed)
	{
		if (keycode == 126)
			move(ar_s, moveSpeed, '+');
		else if (keycode == 125)
			move(ar_s, moveSpeed, '-');
		else if (keycode == 124)
			rotate(ar_s, -moveSpeed);
		else if (keycode == 123)
			rotate(ar_s, moveSpeed);
		else if (keycode == 53)
			ft_close_window(ar_s);
		else
			return (0);
		ft_refresh(ar_s);
	}
	return (1);
}

int		ft_event_released(int keycode, t_tab *ar_s)
{
	(void)keycode;
	ar_s->is_pressed = 0;
	return (0);
}

void	ft_refresh(t_tab *ar_s)
{
	mlx_clear_window(ar_s->window.mlx, ar_s->window.mlx_win);
	ft_raycasting(ar_s->data, &ar_s->ray_data, ar_s->window);
	mlx_put_image_to_window (ar_s->window.mlx, ar_s->window.mlx_win, ar_s->window.img.img, 0, 0);
}