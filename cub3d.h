#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
#include <fcntl.h>

typedef struct	s_data
{
	int resolution[2];
	char *path_ntexture;
	char *path_stexture;
	char *path_wtexture;
	char *path_etexture;
	char *path_sprite;
	char **map;
	char *color_floor;
	char *color_roof;
}				t_data;
#endif