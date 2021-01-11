#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
#include <fcntl.h>

typedef struct	s_data
{
	int 		resolution[2];
	char		*path_ntexture;
	char 		*path_stexture;
	char 		*path_wtexture;
	char 		*path_etexture;
	char 		*path_sprite;
	char 		**map;
	char 		*color_floor;
	char 		*color_roof;
}				t_data;
void			free_all(char **strs, int j);
int				ft_strslen(char **strs);
int				ft_parsing(int fd, t_data *data);
int				fill_struct_parsing(char *line, t_data *data);
void			ft_print_struct(t_data data);
char			**ft_strsjoin(char **s1, char *s2);
void			init_data(t_data *data);
int				fill_struct_parsing(char *line, t_data *data);
int 			fill_struct_parsing_texture(char **line_split, t_data *data);
int				ft_map_is_valid(t_data data);
int				map_line_is_valid(char *map_line);
int				struct_is_valid(t_data data);
int    			ft_close(int bool);
int    			ft_error_msg(int errnum);
int    ft_error_msg_perso(char *error_msg);
// REMOVE WHEN PUSH
void			ft_print_strs(char **strs);
void			ft_print_struct(t_data data);
#endif