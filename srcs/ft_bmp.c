/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:49:06 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/14 21:49:06 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define _height 1080
#define _width 1920
#define _bitsperpixel 24
#define _planes 1
#define _compression 0
#define _pixelbytesize _height*_width*_bitsperpixel/8
#define _filesize _pixelbytesize+sizeof(bitmap)
#define _xpixelpermeter 2835 //2835 , 72 DPI
#define _ypixelpermeter 2835 //2835 , 72 DPI
#define pixel 0xFF


void	ft_init_header_bmp(t_bitmap *pbitmap)
{
	strcpy(pbitmap->fileheader.signature,"BM");
	pbitmap->fileheader.filesize = _filesize;
	pbitmap->fileheader.reserved = 0;
	pbitmap->fileheader.fileoffset_to_pixelarray = sizeof(t_bitmap);
	pbitmap->bitmapinfoheader.dibheadersize = sizeof(pbitmap->t_bitmapinfoheader);
	pbitmap->bitmapinfoheader.width = _width;
	pbitmap->bitmapinfoheader.height = _height;
	pbitmap->bitmapinfoheader.planes = _planes;
	pbitmap->bitmapinfoheader.bitsperpixel = _bitsperpixel;
	pbitmap->bitmapinfoheader.compression = _compression;
	pbitmap->bitmapinfoheader.imagesize = _pixelbytesize;
	pbitmap->bitmapinfoheader.ypixelpermeter = _ypixelpermeter;
	pbitmap->bitmapinfoheader.xpixelpermeter = _xpixelpermeter;
	pbitmap->bitmapinfoheader.numcolorspallette = 0;
}

void	ft_create_image_bmp(int *pixelbuffer)
{
	memset(pixelbuffer,pixel,_pixelbytesize);
}

void	ft_bmp (char *filename)
{
	int fp = open(filename, O_WRONLY | O_APPEND | O_CREAT);
	bitmap *pbitmap  = (bitmap*)calloc(1,sizeof(t_bitmap));
	int *pixelbuffer = (int *)malloc(_pixelbytesize);

	ft_init_header_bmp(pbitmap);
	write(fp, pbitmap, sizeof(bitmap)); // WRITE HEADER
	ft_create_image_bmp(pixelbuffer);
	write(fp, pixelbuffer, _pixelbytesize); // WRITE IMAGE
	close(fp);
	free(pbitmap);
	free(pixelbuffer);
}
