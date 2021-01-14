/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:07:01 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/14 13:46:23 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_close(int bool, t_data *data)
{
	free_struct(data);
	// DESTROY WINDOW
	if (bool)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}


void	miss_element(t_data *data)
{
	if (!data->map)
		ft_error_msg_perso("Miss map", data);
	if (!data->path_ntexture)
		ft_error_msg_perso("Miss map", data);
	if (!data->path_stexture)
		ft_error_msg_perso("Miss map", data);
	if (!data->path_wtexture)
		ft_error_msg_perso("Miss map", data);
	if (!data->path_etexture)
		ft_error_msg_perso("Miss map", data);
	if (!data->path_sprite)
		ft_error_msg_perso("Miss map", data);
	if (!data->color_floor)
		ft_error_msg_perso("Miss map", data);
	if (!data->color_roof)
		ft_error_msg_perso("Miss map", data);
}

int		ft_error_msg(int errnum, t_data *data)
{
	ft_printf("Error\n%s\n", strerror(errnum));
	ft_close(0, data);
	return (0);
}

int    ft_error_msg_perso(char *error_msg, t_data *data)
{
	ft_printf("Error\n%s\n", error_msg);
	ft_close(0, data);
	return (0);
}

void     ft_error_data(char **line_split, t_data *data, char *data_str)
{
	if (ft_strslen(line_split) != 2)
        ft_error_msg(79, data);
    if (data_str != NULL)
        ft_error_msg_perso("Duplicate Data", data);
}