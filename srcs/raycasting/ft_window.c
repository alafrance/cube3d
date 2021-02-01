/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:02:11 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/01 19:34:40 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_window(t_window *window, t_data data)
{
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, data.resolution[0], data.resolution[1], "CUB3D");
	window->img.img = mlx_new_image(window->mlx, data.resolution[0],
					data.resolution[1]);
	window->img.addr = (int*)mlx_get_data_addr(window->img.img, 
										&(window->img.bits_per_pixel),
										&(window->img.line_length),
										&(window->img.endian));
	window->texture.img = mlx_xpm_file_to_image(window->mlx, data.path_ntexture, &(window->texture.width), &(window->texture.height));
	window->texture.addr = (int*)mlx_get_data_addr(window->texture.img, &(window->texture.bits_per_pixel), &(window->texture.line_length),
										&(window->texture.endian));
}

int	change_color_in_hexa(char *color)
{
	int h_color;
	char **color_split;
	
	color_split = ft_split(color, ',');
	
	h_color = ft_atoi(color_split[0]) * ft_power(16, 4) + ft_atoi(color_split[1]) * ft_power(16, 2) + ft_atoi(color_split[2]);
	return (h_color);	
}

void	ft_display_column(t_window window, t_ray *ray_data, t_data data, int column)
{
	long color_floor;
	long color_roof;
	int i;

	color_floor = change_color_in_hexa(data.color_floor);
	color_roof = change_color_in_hexa(data.color_roof);
	if (ray_data->step_tex_x >= window.texture.width)
		ray_data->step_tex_x = 0;
	i = ray_data->step_tex_x;
	while (column < ray_data->draw[0] * data.resolution[0])
	{
		window.img.addr[column] = color_floor;
		column += data.resolution[0];
	}
	while (column <= data.resolution[0] * ray_data->draw[1])
	{
		window.img.addr[column] = window.texture.addr[i];
		if (i >= window.texture.height)
			i = 0;
		else
			i += window.texture.height;	
		column += data.resolution[0];
	}
	while (column < data.resolution[0] * data.resolution[1])
	{
		window.img.addr[column] = color_roof;
		column += data.resolution[0];
	}
	ray_data->step_tex_x++;
}

int		ft_close_window(t_tab *ar_s)
{
	ft_close(1, &(ar_s->data));
	return (1);
}

		// if (ray_data->rayDir[0] < 0 && ray_data->side == 0) // N
		// 	window.img.addr[column] = window.texture.addr[0];
		// else if (ray_data->rayDir[0] > 0 && ray_data->side == 0) // S
		// 	window.img.addr[column] = 0x00FF00;
		// else if (ray_data->rayDir[1] > 0 && ray_data->side == 1) // E
		// 	window.img.addr[column] = 0xFFFFFF;
		// else if (ray_data->rayDir[1] < 0 && ray_data->side == 1) // W
		// 	window.img.addr[column] = 0x0000FF;