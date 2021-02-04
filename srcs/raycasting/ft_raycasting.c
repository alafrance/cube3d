/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:46:25 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/04 17:41:25 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_refresh_raycasting(t_tab *ar_struct)
{
	ft_init_window_after(&ar_struct->window, ar_struct->data);
	mlx_clear_window(ar_struct->window.mlx, ar_struct->window.mlx_win);
	ft_raycasting(ar_struct->data, &ar_struct->ray_data, ar_struct->window);
	ft_put_sprite(&ar_struct->window, ar_struct->data, ar_struct->ray_data);
	mlx_put_image_to_window(ar_struct->window.mlx, ar_struct->window.mlx_win, ar_struct->window.img.img, 0, 0);
}

void	ft_raycasting(t_data data, t_ray *ray_data, t_window window)
{
	int column;

	column = -1;
	while (++column < data.resolution[0])
	{
		init_ray_data_after(data, ray_data);
		*ray_data = calculate_distance(data, *ray_data, column);
		ft_calculate_draw_marge(ray_data, data);
		ft_choose_texture(&window, *ray_data);
		ft_calculate_texture(ray_data, *window.texture_used, data);
		ft_display_column(window, ray_data, data, column);
	}
	// ft_print_struct(*ray_data, data);
}

void	ft_calculate_draw_marge(t_ray *ray_data, t_data data)
{
	if (ray_data->dist == 0.0)
		ray_data->h_wall = data.resolution[1];
	else
		ray_data->h_wall = (int)(data.resolution[1] / ray_data->dist);
	ray_data->draw[0] = -ray_data->h_wall / 2 + data.resolution[1] / 2;
	if (ray_data->draw[0] < 0)
		ray_data->draw[0] = 0;
	ray_data->draw[1] = ray_data->h_wall / 2 + data.resolution[1] / 2;
	if (ray_data->draw[1] >= data.resolution[1])
		ray_data->draw[1] = data.resolution[1] - 1;

}

void	ft_choose_texture(t_window *window, t_ray ray_data)
{
	if (ray_data.rayDir[0] < 0 && ray_data.side == 0)
		window->texture_used = &window->n_texture;
	else if (ray_data.rayDir[0] > 0 && ray_data.side == 0)
		window->texture_used = &window->s_texture;
	else if (ray_data.rayDir[1] > 0 && ray_data.side == 1)
		window->texture_used = &window->e_texture;
	else if (ray_data.rayDir[1] < 0 && ray_data.side == 1)
		window->texture_used = &window->w_texture;
}
