/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:49:06 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/15 15:05:24 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	ft_init_header_bmp(t_bitmap *pbitmap, t_data data, int filesize, int pixelbytesize)
{
	pbitmap->fileheader.signature[0] = 'B';
	pbitmap->fileheader.signature[1] = 'M';
	pbitmap->fileheader.filesize = filesize;
	pbitmap->fileheader.reserved = 0;
	pbitmap->fileheader.fileoffset_to_pixelarray = sizeof(t_bitmap);
	pbitmap->bitmapinfoheader.dibheadersize = sizeof(t_bitmapinfoheader);
	pbitmap->bitmapinfoheader.width = data.resolution[0];
	pbitmap->bitmapinfoheader.height = data.resolution[1];
	pbitmap->bitmapinfoheader.planes = 1;
	pbitmap->bitmapinfoheader.bitsperpixel = 24;
	pbitmap->bitmapinfoheader.compression = 0;
	pbitmap->bitmapinfoheader.imagesize = pixelbytesize;
	pbitmap->bitmapinfoheader.ypixelpermeter = 0x130B;
	pbitmap->bitmapinfoheader.xpixelpermeter = 0x130B;
	pbitmap->bitmapinfoheader.numcolorspallette = 0;
}

void	ft_create_img(char **pixelbuffer, t_tab *ar_s, int pixelbytesize)
{
	int			i;

	i = 0;
	if (!(*pixelbuffer = malloc(24)))
		ft_error_msg_perso("Malloc error", NULL);
	ft_memset(*pixelbuffer, ar_s->window.img.addr[i], 1);
}
int		ft_bmp(t_tab *ar_s)
{
	int			fd;
	t_bitmap	*pbitmap;
	int			pixelbytesize;
	int			filesize;
	char		*pixelbuffer;

   	ft_refresh_raycasting(ar_s, 0);
	pixelbytesize = ar_s->data.resolution[0] * ar_s->data.resolution[1] * 24 / 8;
	filesize = pixelbytesize + sizeof(t_bitmap);
	fd = open("cub3d.bmp",  O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (!(pbitmap  = calloc(1,sizeof(t_bitmap))))
		return (ft_error_msg_perso("Malloc error", NULL));
	if (!(pixelbuffer = malloc(24)))
		ft_error_msg_perso("Malloc error", NULL);
	ft_init_header_bmp(pbitmap, ar_s->data, filesize, pixelbytesize);
	// ft_create_image(&pixelbuffer, ar_s, pixelbytesize);
	write(fd, pbitmap, sizeof(t_bitmap));
	// memset(pixelbuffer, , pixelbytesize);
	write(fd, pixelbuffer, pixelbytesize);
	close(fd);
	free(pbitmap);
	free(pixelbuffer);
	return (1);
}