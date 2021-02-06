/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:58:45 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/06 11:23:50 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void launch_minilibx(t_window window, t_tab ar_s)
{
	mlx_hook(window.mlx_win, 2, 0, ft_event_pressed, &ar_s);
	mlx_hook(window.mlx_win, 3, 0, ft_event_released, &ar_s);
	mlx_hook(window.mlx_win, 17, 0L, ft_close_window, &ar_s);
	mlx_loop_hook(window.mlx, ft_loop_hook, &ar_s);
	mlx_loop(window.mlx);
}

int main(int ac, char **av)
{
    int     fd;
	t_tab ar_s;

	init_data(&ar_s.data);
    if (ac != 2)
         return (ft_error_msg(22, &ar_s.data));
    fd = open(av[1], O_RDWR);
    if (fd <= 0 || !ft_is_format(av[1], ".cub"))
        return (ft_error_msg(22, &ar_s.data));
    ft_parsing(fd, &ar_s.data);
	ft_init_window_before(&ar_s.window, ar_s.data);
	init_ray_data_before(&ar_s.ray_data, ar_s.data);
	init_button(&ar_s.key);
	ft_refresh_raycasting(&ar_s);
	launch_minilibx(ar_s.window, ar_s);
	close(fd);
	free_struct(&ar_s.data);
	return (1);
}