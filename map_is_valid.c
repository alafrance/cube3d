/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:53:13 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/11 17:22:26 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     ft_map_is_valid(t_data data)
{
    int i;
    int is_player;

    is_player = 0;
    i = 0;
    if (!struct_is_valid(data))
       return (ft_print_error("Wrong data"));
    if (!data.map)
        return (0);
    while (data.map[i])
    {
        if (ft_strchr(data.map[i], 'N'))
        {
            if (is_player)
                return (0);
            is_player = 1;
        }
        if (!map_line_is_valid(data.map[i]))
        {
            free_all(data.map, ft_strslen(data.map));
            return (0);
        }
        i++;
    }
    return (1);
}

int		map_line_is_valid(char *map_line)
{
	int i;

	i = 0;
	if (!map_line || map_line[0] != '1')	
		return (0);
	while (map_line[i + 1])
	{
		if (!ft_strchr("012N ", map_line[i]))
			return (0);
		i++;
	}
	if (map_line[i] != '1')
		return (0);
	return (1);
}

int	struct_is_valid(t_data data)
{
	int fd;

	if (data.resolution[0] <= 0 || data.resolution[1] <= 0)
		return (0);
	if ((fd = open(data.path_etexture, O_RDONLY)) <= 0 ||
		(fd = open(data.path_wtexture, O_RDONLY)) <= 0 ||
			(fd = open(data.path_ntexture, O_RDONLY)) <= 0 ||
				(fd = open(data.path_stexture, O_RDONLY)) <= 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}