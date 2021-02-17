#ifndef STRUCT_BMP_H
# define STRUCT_BMP_H

typedef struct			s_fileheader
{
	int					file_size;
	int					header_size;
	int					bytes_size;
	int					image_size;
	int					planes;
	int					bytes_number;
	char				header[54];
}						t_fileheader;

#endif
