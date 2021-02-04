/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:54:57 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/04 17:08:06 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	*ft_pick_sprite(t_data data, t_ray ray_data)
{
	t_sprite	*sprite;
	int			num_sprite;

	sprite = NULL;
	(void)ray_data;
	num_sprite = ft_count_sprite(data);
	dprintf(1, "%d\n", num_sprite);
	return (sprite);
}

int		ft_count_sprite(t_data data)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}