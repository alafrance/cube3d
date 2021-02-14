#ifndef STRUCT_BMP_H
# define STRUCT_BMP_H

# pragma pack(push, 1)

typedef struct s_fileheader{
	char signature[2];
	int filesize;
	int reserved;
	int fileoffset_to_pixelarray;
} t_fileheader;

typedef struct s_bitmapinfoheader{
	int dibheadersize;
	int width;
	int height;
	short int planes;
	short int bitsperpixel;
	int compression;
	int imagesize;
	int ypixelpermeter;
	int xpixelpermeter;
	int numcolorspallette;
	int mostimpcolor;
} t_bitmapinfoheader;

typedef struct s_bitmap {
	t_fileheader fileheader;
	t_bitmapinfoheader bitmapinfoheader;
} t_bitmap;

# pragma pack(pop)

#endif