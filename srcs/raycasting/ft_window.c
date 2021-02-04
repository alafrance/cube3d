/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:02:11 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/04 17:44:05 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_window_after(t_window *window, t_data data)
{
	window->img.img = mlx_new_image(window->mlx, data.resolution[0],
					data.resolution[1]);
	window->img.addr = (int*)mlx_get_data_addr(window->img.img, 
										&(window->img.bits_per_pixel),
										&(window->img.line_length),
										&(window->img.endian));
	ft_open_file(&window->n_texture, window->mlx, data.path_ntexture);
	ft_open_file(&window->s_texture, window->mlx, data.path_stexture);
	ft_open_file(&window->e_texture, window->mlx, data.path_etexture);
	ft_open_file(&window->w_texture, window->mlx, data.path_wtexture);
	ft_open_file(&window->sprite_file, window->mlx, data.path_sprite);
}

void	ft_init_window_before(t_window *window, t_data data)
{
	window->number_sprites = ft_count_sprite(data);
	window->sprite = ft_pick_sprite(data, window->number_sprites);
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, data.resolution[0], data.resolution[1], "CUB3D");
}


void ft_open_file(t_img *texture, void *mlx, char *path_texture)
{
	texture->img = mlx_xpm_file_to_image(mlx, path_texture, &(texture->width), &(texture->height));
	texture->addr = (int*)mlx_get_data_addr(texture->img, &(texture->bits_per_pixel), &(texture->line_length),
										&(texture->endian));
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
	i = 0;
	while (i < ray_data->draw[0])
	{
		window.img.addr[i * data.resolution[0] + column] = color_floor;
		i++;
	}
	while (i < ray_data->draw[1])
	{
		ray_data->texy = (int)ray_data->texpos & (window.texture_used->height - 1);
		ray_data->texpos += ray_data->step_tex;
		window.img.addr[i * data.resolution[0] + column] = window.texture_used->addr[window.texture_used->height * ray_data->texy + ray_data->texx];
		i++;
	}
	while (i < data.resolution[1])
	{
		window.img.addr[i * data.resolution[0] + column] = color_roof;
		i++;
	}
	ray_data->step_tex_x++;
}

int		ft_close_window(t_tab *ar_s)
{
	ft_close(1, &(ar_s->data));
	return (1);
}
