/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:49:06 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/14 22:40:33 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


#define _width 1920
#define _height 1080
#define _bitsperpixel 24
#define _pixelbytesize _height*_width*_bitsperpixel/8
#define _filesize _pixelbytesize+sizeof(t_bitmap)


void	ft_init_header_bmp(t_bitmap *pbitmap)
{
	pbitmap->fileheader.signature[0] = 'B';
    pbitmap->fileheader.signature[1] = 'M';
	pbitmap->fileheader.filesize = _filesize;
	pbitmap->fileheader.reserved = 0;
	pbitmap->fileheader.fileoffset_to_pixelarray = sizeof(t_bitmap);
	pbitmap->bitmapinfoheader.dibheadersize = sizeof(t_bitmapinfoheader);
	pbitmap->bitmapinfoheader.width = _width;
	pbitmap->bitmapinfoheader.height = _height;
	pbitmap->bitmapinfoheader.planes = 1;
	pbitmap->bitmapinfoheader.bitsperpixel = _bitsperpixel;
	pbitmap->bitmapinfoheader.compression = 0;
	pbitmap->bitmapinfoheader.imagesize = _pixelbytesize;
	pbitmap->bitmapinfoheader.ypixelpermeter = 0x130B;
	pbitmap->bitmapinfoheader.xpixelpermeter = 0x130B;
	pbitmap->bitmapinfoheader.numcolorspallette = 0;
}

void	ft_create_image_bmp(int *pixelbuffer)
{
	memset(pixelbuffer, 0xFF,_pixelbytesize);
}

int ft_bmp (char *filename, t_data data)
{
	int fp = open(filename, O_WRONLY | O_APPEND | O_CREAT);
	t_bitmap *pbitmap  = (t_bitmap*)calloc(1,sizeof(t_bitmap));
	int *pixelbuffer = (int *)malloc(_pixelbytesize);

    if (pbitmap == NULL || pixelbuffer == NULL)
        return (ft_error_msg_perso("Malloc error", &data));
	ft_init_header_bmp(pbitmap);
	ft_create_image_bmp(pixelbuffer);
	write(fp, pbitmap, sizeof(t_bitmap)); // WRITE HEADER
	write(fp, pixelbuffer, _pixelbytesize); // WRITE IMAGE
	close(fp);
	free(pbitmap);
	free(pixelbuffer);
    return (1);
}