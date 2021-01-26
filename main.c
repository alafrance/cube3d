/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:58:45 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/26 17:55:33 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	data->pos_player[0] = -1;
	data->pos_player[1] = -1;
	data->pos_camera = 0;
}

// int main(int ac, char **av)
// {
//     t_data  data;
//     int     fd;
// 	init_data(&data);
//     if (ac != 2)
//          return (ft_error_msg(22, &data));
//     fd = open(av[1], O_RDWR);
//     if (fd <= 0 || !ft_is_format(av[1], ".cub"))
//         return (ft_error_msg(22, &data));
//     ft_parsing(fd, &data);
// 	ft_display_raycasting(data);
// 	free_struct(&data);
// 	close(fd);
// 	return (1);
// }


typedef struct  s_data_img {
    void        *img;
    int         *addr;
    int         bits_per_pixel;
    int         size_line;
    int         endian;
	int			width;
	int			height;
}               t_data_img;

int main()
{
	void *mlx;
	void *mlx_win;
	t_data data;
	int i;
	
	i = 0;
	data.resolution[0] = 1920;
	data.resolution[0] = 1080;
	window.mlx = mlx_init();
	mlx_new_window(mlx, 1920, 1080, "coucou");
	img.img = mlx_xpm_file_to_image (mlx, "textures/brown_b.xpm", &(img.width), &(img.height));
	img.addr = (int*)mlx_get_data_addr (img.img, &(img.bits_per_pixel), &(img.size_line),&(img.endian));
	printf("%d\n", img.addr[100]);
	while (i != 1080)
	{
		ft_display_column()
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
/* PRINT TEXTURE
RAPPORT TAILLE 
calcul float
*/