/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:53:57 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/11 21:08:29 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parsing(int fd, t_data *data)
{
	char	*line;
	int		gnl;

	line = NULL;
	gnl = 0;
	while ((gnl = get_next_line(fd, &line)) > 0
		&& fill_struct_parsing(line, data))
		free(line);
	while (gnl == 0 || gnl == 1)
	{
		if (!map_line_is_valid(line))
		{
			free(line);
            return (ft_error_msg_perso("Wrong data", data));
		}
		data->map = ft_strsjoin(data->map, line);
		free(line);
		if (gnl == 0)
			break;
		gnl = get_next_line(fd, &line);
	}
	return (1);
}

int		ft_path_sprite(char **line_split, t_data *data)
{

}
int		ft_color_floor(char **line_split, t_data *data)
{

}

int		ft_color_roof(char **line_split, t_data *data)
{
	
}

int		ft_resolution(char **line_split, t_data *data)
{
	
}

int		ft_init_pos(char **line_split, int *pos)
{
	if (!ft_strcmp(line_split[0], "NO"))
		*pos = 0;
	else if (!ft_strcmp(line_split[0], "SO"))
		*pos = 1;
	else if (!ft_strcmp(line_split[0], "WE"))
		*pos = 2;
	else if (!ft_strcmp(line_split[0], "EA"))
		*pos = 3;
	else if (!ft_strcmp(line_split[0], "S"))
		*pos = 4;
	else if (!ft_strcmp(line_split[0], "F"))
		*pos = 5;
	else if (!ft_strcmp(line_split[0], "C"))
		*pos = 6;
	else if (!ft_strcmp(line_split[0], "R"))
		*pos = 7;
	else
		*pos = -1;
	return (*pos);
}
int		fill_struct_parsing(char *line, t_data *data)
{
	char	**line_split;
	int		pos;
	int 	(*ft_parse[8])(char**, t_data *);

	line_split = ft_split(line, ' ');
	if (ft_init_pos(line_split, &pos) == -1)
		return (ft_error_msg_perso("Wrong ID for data", data));
	ft_parse[0] = &ft_path_ntexture;
	ft_parse[1] = &ft_path_stexture;
	ft_parse[2] = &ft_path_wtexture;
	ft_parse[3] = &ft_path_etexture;
	ft_parse[4] = &ft_path_sprite;
	ft_parse[5] = &ft_color_floor;
	ft_parse[6] = &ft_color_roof;
	ft_parse[7] = &ft_resolution;
	if (!line_split)
		return (ft_error_msg(22, data));
	return (ft_parse[pos](line_split, data));
	return (1);
}
