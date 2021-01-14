/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:53:57 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/13 19:38:58 by alafranc         ###   ########lyon.fr   */
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
	while (gnl >= 0)
	{
		data->map = ft_strsjoin(data->map, line);
		free(line);
		if (gnl == 0)
			break;
		gnl = get_next_line(fd, &line);
	}
	if (!data->path_etexture || !data->path_ntexture || !data->path_sprite
		|| !data->path_stexture || !data->path_wtexture || !data->color_floor
		|| !data->color_roof || !data->resolution[0] || !data->resolution[1])
		return (ft_error_msg_perso("Miss data", data));
	return (1);
}

void	ft_init_pos(char **line_split, int *pos)
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
}

int		fill_struct_parsing(char *line, t_data *data)
{
	char	**line_split;
	int		pos;
	void 	(*ft_parse[8])(char**, t_data *);

	if (!ft_strlen(line))
		return (1);
	line_split = ft_split(line, ' ');
	ft_init_pos(line_split, &pos);
	if (pos == -1)
		return (0);
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
	ft_parse[pos](line_split, data);
	free_all(line_split, ft_strslen(line_split));
	return (1);
}

int	ft_is_format(char *filename, char *extension)
{
	int i = ft_strlen(filename) - 1;
	if (i <= 3 || ft_strlen(extension) != 4)
		return(0);
	if (filename[i] == extension[3] &&
		filename[i - 1] == extension[2] && filename[i - 2] == extension[1] 
	 		&& filename[i - 3] == extension[0])
		return (1);
	return (0);
}
