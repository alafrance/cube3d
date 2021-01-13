/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:23:13 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/13 17:18:55 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     ft_error_data(char **line_split, t_data *data, char *data_str)
{
	if (ft_strslen(line_split) != 2)
        return(ft_error_msg(79, data));
    (void)data_str;
    //if (data_str != NULL)
        //return (ft_error_msg_perso("Duplicate Data", data));
    return (1);
}

int		ft_path_sprite(char **line_split, t_data *data)
{
	if (!ft_path_texture_valid(line_split, data, data->path_sprite))
        return (0);
	data->path_sprite = line_split[1];
	return (1);
}

int		ft_color(char **line_split, t_data *data)
{
    int i;
    int j;
    int count;

    count = 0;
    i = 0;
    j = 0;
    if (!ft_error_data(line_split, data, data->color_floor))
        return (0);
    while (line_split[1][i])
    {
        j++;
        if (line_split[1][i] == ',')
        {
            if (j == 0)
                return (ft_error_msg_perso("Wrong Data", data));
            count++;
            j = 0;
        }
        i++;
    }
    if (count != 2 || j == 0)
        return (ft_error_msg_perso("Wrong Data", data));
	return (1);
}

int ft_color_roof(char **line_split, t_data *data)
{
    if (!ft_color(line_split, data))
        return (0);
	data->color_roof = line_split[1];   
    return (1);
}

int ft_color_floor(char **line_split, t_data *data)
{
    if (!ft_color(line_split, data))
        return (0);
	data->color_floor = line_split[1];
    return (1);
}

int		ft_resolution(char **line_split, t_data *data)
{
	if (ft_strslen(line_split) != 3)
		return(ft_error_msg(79, data));
    if (data->resolution[0] != 0 || data->resolution[1] != 0)
        return (ft_error_msg_perso("Duplicate Data", data));
	data->resolution[0] = ft_atoi(line_split[1]);
	data->resolution[1] = ft_atoi(line_split[2]);
    if (data->resolution[0] <= 0 || data->resolution[1] <= 0)
        return (ft_error_msg_perso("Error Resolution", data));
	return (1);	
}