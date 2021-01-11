/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:57:24 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/11 21:09:56 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_path_ntexture(char **line_split, t_data *data)
{
	if (!ft_path_texture(line_split, data))
		return (0);
	data->path_ntexture = line_split[1];
	free_all(line_split, ft_strslen(line_split));
	return (1);
}

int		ft_path_stexture(char **line_split, t_data *data)
{
	if (!ft_path_texture(line_split, data))
		return (0);
	data->path_stexture = line_split[1];
	free_all(line_split, ft_strslen(line_split));
	return (1);
}

int		ft_path_wtexture(char **line_split, t_data *data)
{
	if (!ft_path_texture(line_split, data))
		return (0);
	data->path_wtexture = line_split[1];
	free_all(line_split, ft_strslen(line_split));
	return (1);
}

int		ft_path_etexture(char **line_split, t_data *data)
{
	if (!ft_path_texture(line_split, data))
		return (0);
	data->path_etexture = line_split[1];
	free_all(line_split, ft_strslen(line_split));
	return (1);
}

int		ft_path_texture(char **line_split, t_data *data)
{
	if (ft_strslen(line_split) != 2)
		ft_error_msg(79, data);
	if (data->path_ntexture != NULL)
	{
		free_all(line_split, ft_strslen(line_split));
		return (ft_error_msg_perso("Duplicate Data", data));
	}
	return (1);
}