/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:41:02 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/05 10:24:34 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calc_height_sprite(t_sprite *sprite, t_data data)
{
	sprite->sprite_height = abs((int)((data.resolution[1] / sprite->transformY))) / VDIV;
	sprite->draw_sprite_y[0] = -sprite->sprite_height / 2 + data.resolution[1] / 2 + sprite->v_move_screen;
	if (sprite->draw_sprite_y < 0)
		sprite->draw_sprite_y[0] = 0;
	sprite->draw_sprite_y[1] = sprite->sprite_height / 2 + data.resolution[1] / 2 + sprite->v_move_screen;
	if (sprite->draw_sprite_y[1] >= data.resolution[1])
		sprite->draw_sprite_y[1] = data.resolution[1] - 1;
}

void	ft_calc_width_sprite(t_sprite *sprite, t_data data)
{
	sprite->sprite_width = abs((int)((data.resolution[1] / sprite->transformY))) / UDIV;
	sprite->draw_sprite_x[0] = -sprite->sprite_width / 2 + sprite->sprite_screen_x;
	if (sprite->draw_sprite_x[0] < 0)
		sprite->draw_sprite_x[0] = 0;
	sprite->draw_sprite_x[1] = sprite->sprite_width / 2 + sprite->sprite_screen_x;
	if (sprite->draw_sprite_x[1] >= data.resolution[0])
		sprite->draw_sprite_x[1] = data.resolution[0] - 1;
}

void	ft_init_sprite(t_sprite *sprite, t_ray ray_data, t_data data)
{
	sprite->dist = ft_power(data.pos_player[0] - sprite->x, 2) + ft_power(data.pos_player[1] - sprite->y, 2);
	sprite->x_relative = sprite->x - data.pos_player[0];
	sprite->y_relative = sprite->y - data.pos_player[1];
	sprite->invDet = 1.0 / (ray_data.plane[0] * ray_data.dir[1] - ray_data.dir[0] * ray_data.plane[1]);
	sprite->transformX =  sprite->invDet * (ray_data.dir[1] * sprite->x_relative - ray_data.dir[0] * sprite->y_relative); 
	sprite->transformY =  sprite->invDet * (-ray_data.plane[1] * sprite->x_relative - ray_data.plane[0] * sprite->y_relative);
	sprite->sprite_screen_x = (int)(data.resolution[0] / 2) * (1 + sprite->transformX / sprite->transformY);
	sprite->v_move_screen = (int)(VMOVE / sprite->transformY);
}

void	ft_print_sprite_on_screen(t_sprite sprite, t_data data, t_ray ray_data, t_window *window)
{
	int i;
	int j;
	int d;
	int texx;
	int texy;
	int color;

	i = sprite.draw_sprite_x[0];
	while (i < sprite.draw_sprite_x[1])
	{
		texx = (int)(256 * (i - (-sprite.sprite_width / 2 + sprite.sprite_screen_x)) * window->sprite_file.width / sprite.sprite_width) / 256;
		j = sprite.draw_sprite_y[0];
		if (sprite.transformY > 0 && i > 0
			&& i < data.resolution[0])
			//  && sprite.transformY < ray_data.dist)
			while (j < sprite.draw_sprite_y[1])
			{
				d = (j - sprite.v_move_screen) * 256 - data.resolution[1] * 128 + sprite.sprite_height * 128;
				texy = ((d * window->sprite_file.height) / sprite.sprite_height) / 256;
				color = window->sprite_file.addr[window->sprite_file.width * texy + texx];
				if (color != 0x980088)
					window->img.addr[j * data.resolution[0] + i] = color;
				j++;
			}
		i++;
	}
}

void	ft_put_sprite(t_window *window, t_data data, t_ray ray_data)
{
	int i;

	i = 0;

	while (i < window->number_sprites)
	{
		ft_init_sprite(&window->sprite[i], ray_data, data);
		ft_calc_height_sprite(&window->sprite[i], data);
		ft_calc_width_sprite(&window->sprite[i], data);
		// ft_print_sprite(window->sprite[i]);
		ft_print_sprite_on_screen(window->sprite[i], data, ray_data, window);
		i++;
	}
}
