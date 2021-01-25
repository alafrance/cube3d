/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:02:11 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/25 13:27:36 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_window(t_window *window, t_data data)
{
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, data.resolution[0]
					, data.resolution[1], "CUB3D");
	window->img.img = mlx_new_image(window->mlx, data.resolution[0],
					data.resolution[1]);
	window->img.addr = mlx_get_data_addr(window->img.img, 
										&(window->img.bits_per_pixel),
										&(window->img.line_length),
										&(window->img.endian));
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	change_color_in_hexa(char *color)
{
	int h_color;
	char **color_split;
	
	color_split = ft_split(color, ',');
	
	h_color = ft_atoi(color_split[0]) * ft_power(16, 4) + ft_atoi(color_split[1]) * ft_power(16, 2) + ft_atoi(color_split[2]);
	return (h_color);	
}

void	ft_display_column(t_window window, t_ray ray_data, t_data data, int column)
{
	int i;

	i = 0;
	while (i < ray_data.draw[0])
		my_mlx_pixel_put(&window.img, column, i++, change_color_in_hexa(data.color_roof));
	while (i < ray_data.draw[1])
		my_mlx_pixel_put(&window.img, column, i++, 0xFF0000);
	while (i < data.resolution[1])
		my_mlx_pixel_put(&window.img, column, i++, change_color_in_hexa(data.color_floor));
}
