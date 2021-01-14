/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:07:01 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/13 20:13:37 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    ft_close(int bool, t_data *data)
{
	// DESTROY WINDOW
	if (data->map)
		free_all(data->map, ft_strslen(data->map));
	if (bool)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
	return (0);
}

int    ft_error_msg(int errnum, t_data *data)
{
	ft_printf("Error\n%s\n", strerror(errnum));
	return (ft_close(0, data));
}

int    ft_error_msg_perso(char *error_msg, t_data *data)
{
	ft_printf("Error\n%s\n", error_msg);
	return (ft_close(0, data));
}

int     ft_error_data(char **line_split, t_data *data, char *data_str)
{
	if (ft_strslen(line_split) != 2)
        return(ft_error_msg(79, data));
    if (data_str != NULL)
        return (ft_error_msg_perso("Duplicate Data", data));
    return (1);
}