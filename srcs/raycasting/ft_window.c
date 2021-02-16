/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:02:11 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/16 23:46:37 by alafranc         ###   ########lyon.fr   */
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

void	fix_resolution_data(t_data *data, t_window window)
{
	int width_max;
	int height_max;

	mlx_get_screen_size(window.mlx, &width_max, &height_max);
	data->resolution[0] = closest_multiple_of_x(data->resolution[0], 64);
	data->resolution[1] = closest_multiple_of_x(data->resolution[1], 64);
	if (data->resolution[0] > width_max)
		data->resolution[0] = width_max;
	if (data->resolution[1] > height_max)
		data->resolution[1] = height_max;
}

void	ft_open_file(t_img *texture, void *mlx, char *path_texture)
{
	texture->img = mlx_xpm_file_to_image(mlx, path_texture, &(texture->width)
					, &(texture->height));
	texture->addr = (int*)mlx_get_data_addr(texture->img,
					&(texture->bits_per_pixel), &(texture->line_length),
					&(texture->endian));
}

int		change_color_in_hexa(char *color)
{
	int		h_color;
	char	**color_split;

	color_split = ft_split(color, ',');
	h_color = ft_atoi(color_split[0]) * ft_power(16, 4) +
			ft_atoi(color_split[1]) * ft_power(16, 2) + ft_atoi(color_split[2]);
	free_all(color_split, ft_strslen(color_split));
	return (h_color);
}

void	ft_display_column(t_window window, t_ray *ray_data, t_data data
		, int column)
{
	long	color_floor;
	long	color_roof;
	int		i;

	color_floor = change_color_in_hexa(data.color_floor);
	color_roof = change_color_in_hexa(data.color_roof);
	i = -1;
	while (++i < ray_data->draw[0])
		window.img.addr[i * data.resolution[0] + column] = color_floor;
	while (i < ray_data->draw[1])
	{
		ray_data->texy = (int)ray_data->texpos &
						(window.texture_used->height - 1);
		ray_data->texpos += ray_data->step_tex;
		window.img.addr[i * data.resolution[0] + column] =
						window.texture_used->addr[window.texture_used->height
						* ray_data->texy + ray_data->texx];
		i++;
	}
	i--;
	while (++i < data.resolution[1])
		window.img.addr[i * data.resolution[0] + column] = color_roof;
	ray_data->step_tex_x++;
}
