/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:54:45 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/11 17:29:25 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_strs(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
		ft_printf("%s\n", strs[i++]);
}

void	ft_print_struct(t_data data)
{
	int i;

	i = 0;
	ft_printf("path_etexture: %s\n", data.path_etexture);
	ft_printf("path_ntexture: %s\n", data.path_ntexture);
	ft_printf("path_stexture: %s\n", data.path_stexture);
	ft_printf("path_wtexture: %s\n", data.path_wtexture);
	ft_printf("path_sprite: %s\n", data.path_sprite);
	ft_printf("color_floor: %s\n", data.color_floor);
	ft_printf("color_roof: %s\n", data.color_roof);
	ft_printf("resolution: %d, %d\n", data.resolution[0], data.resolution[1]);
	if (data.map)
		while (data.map[i])
		{
			ft_printf("map[%d]: %s\n", i, data.map[i]);
			i++;
		}
}


int    ft_close(int bool)
{
    // DESTROY WINDOW
    if (bool)
        exit(EXIT_SUCCESS);
    else
        exit(EXIT_FAILURE);
    return (0);
}

int    ft_error_msg(int errnum)
{
    ft_printf("Error\n%s\n", strreror(errnum));
    return (ft_close(0));
}

int    ft_error_msg_perso(char *error_msg)
{
    ft_printf("Error\n%s\n", error_msg);
    return (ft_close(0));
}