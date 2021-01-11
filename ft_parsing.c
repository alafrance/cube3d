/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:53:57 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/11 17:30:16 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parsing(int fd, t_data *data)
{
	char	*line;
	int		gnl;

	line = NULL;
	gnl = 0;
	init_data(data);
	while ((gnl = get_next_line(fd, &line)) > 0
		&& fill_struct_parsing(line, data))
		free(line);
	while (gnl == 0 || gnl == 1)
	{
		if (!map_line_is_valid(line))
        {
            free_all(data->map, ft_strslen(data->map));
            return (ft_print_error("Wrong data"));
        }
		data->map = ft_strsjoin(data->map, line);
		free(line);
		if (gnl == 0)
			break;
		gnl = get_next_line(fd, &line);
	}
	ft_print_struct(*data);
	return (1);
}

void	init_data(t_data *data)
{
	data->resolution[0] = 0;
	data->resolution[1] = 0;
	data->path_ntexture = NULL;
	data->path_stexture = NULL;
	data->path_wtexture = NULL;
	data->path_etexture = NULL;
	data->path_sprite = NULL;
	data->map = NULL;
	data->color_floor = NULL;
	data->color_roof = NULL;
}

int		ft_path_ntexture(char **line_split, t_data *data)
{
	if (ft_strslen(line_split) != 2)
		ft_error_msg(22);
	if (data->path_ntexture != NULL)
		return (ft_error_msg_perso("Duplicate Data"));
	return (line_split[1]);
}

int		fill_struct_parsing(char *line, t_data *data)
{
	char	**line_split;
	int		pos;
	int 	(*ft_parse[7])(char**, t_data *);

	ft_parse[0] = &ft_path_ntexture;
	/*
	ft_op[0] = &ft_path_stexture;
	ft_op[0] = &ft_path_wtexture;
	ft_op[0] = &ft_path_etexture;
	ft_op[0] = &ft_path_sprite;
	ft_op[0] = &ft_path_ntexture;
	*/
	line_split = ft_split(line, ' ');
	if (!line_split)
		return (ft_error_msg(22));
	if (!ft_strcmp(line_split[0], "NO"))
		pos = 0;
	return(ft_parse[pos](line_split, data));
	/*
	else if (!ft_strcmp(line_split[0], "SO"))
		pos = 0;
	else if (!ft_strcmp(line_split[0], "WE"))
		pos = 0;
	else if (!ft_strcmp(line_split[0], "EA"))
		pos = 0;
	else if (!ft_strcmp(line_split[0], "R"))
		pos = 0;
	*/

/*
	if (ft_strslen(line_split) == 2 && !ft_strcmp(line_split[0], "S")
		&& data->path_sprite == NULL)
		data->path_sprite = line_split[1];
	else if (ft_strslen(line_split) == 2 && !ft_strcmp(line_split[0], "F")
		&& data->color_floor == NULL)
		data->color_floor = line_split[1];
	else if (ft_strslen(line_split) == 2 && !ft_strcmp(line_split[0], "C")
		&& data->color_roof == NULL)
		data->color_roof = line_split[1];
	else if (ft_strslen(line_split) == 3 && !ft_strcmp(line_split[0], "R")
		&& data->resolution[0] == 0 && data->resolution[1] == 0)
	{
		data->resolution[0] = ft_atoi(line_split[1]);
		data->resolution[1] = ft_atoi(line_split[2]);
	}
	else
		return (0);
		*/
	return (1);
}

int fill_struct_parsing_texture(char **line_split, t_data *data)
{
	if (ft_strslen(line_split) == 2 && !ft_strcmp(line_split[0], "NO")
		&& data->path_ntexture == NULL)
		data->path_ntexture = line_split[1];
	else if (ft_strslen(line_split) == 2 && !ft_strcmp(line_split[0], "SO")
		&& data->path_stexture == NULL)
		data->path_stexture = line_split[1];
	else if (ft_strslen(line_split) == 2 && !ft_strcmp(line_split[0], "WE")
		&& data->path_wtexture == NULL)
		data->path_wtexture = line_split[1];
	else if (ft_strslen(line_split) == 2 && !ft_strcmp(line_split[0], "EA")
		&& data->path_etexture == NULL)
		data->path_etexture = line_split[1];
	else
		return (0);
	return (1);
}


