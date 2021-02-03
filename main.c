/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:58:45 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/03 13:21:29 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_data  data;
    int     fd;
	t_ray ray_data;
	t_window window;
	t_tab ar_s;

	init_data(&data);
    if (ac != 2)
         return (ft_error_msg(22, &data));
    fd = open(av[1], O_RDWR);
    if (fd <= 0 || !ft_is_format(av[1], ".cub"))
        return (ft_error_msg(22, &data));
    ft_parsing(fd, &data);
	ft_init_window(&window, data);
	init_ray_data_before(&ray_data, data);
	init_tab_ar_s(&ar_s, ray_data, data, window);
	ft_refresh_raycasting(&ar_s);
	mlx_hook(window.mlx_win, 2, 0, ft_event_pressed, &ar_s);
	mlx_hook(window.mlx_win, 3, 0, ft_event_released, &ar_s);
	mlx_hook(window.mlx_win, 17, 0L, ft_close_window, &ar_s);
	mlx_loop_hook(window.mlx, ft_loop_hook, &ar_s);
	mlx_loop(window.mlx);
	close(fd);
	free_struct(&data);
	return (1);
}