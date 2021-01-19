#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <string.h>

typedef struct	s_data
{
	int			resolution[2];
	char		*path_ntexture;
	char		*path_stexture;
	char		*path_wtexture;
	char		*path_etexture;
	char		*path_sprite;
	char		**map;
	char		*color_floor;
	char		*color_roof;
	int			pos_player[2];
	char		pos_camera;
}				t_data;
void			ft_parsing(int fd, t_data *data);
int				fill_struct_parsing(char *line, t_data *data);
void			ft_print_struct(t_data data);
void			init_data(t_data *data);
int				fill_struct_parsing(char *line, t_data *data);
int				fill_struct_parsing_texture(char **line_split, t_data *data);
int				map_line_is_valid(char *map_line);
int				struct_is_valid(t_data data);
void			ft_close(int bool, t_data *data);
int				ft_error_msg(int errnum, t_data *data);
int				ft_error_msg_perso(char *error_msg, t_data *data);
int				ft_path_texture_valid(char **line_split
				, t_data *data, char *texture);
void			ft_path_ntexture(char **line_split, t_data *data);
void			ft_path_stexture(char **line_split, t_data *data);
void			ft_path_wtexture(char **line_split, t_data *data);
void			ft_path_etexture(char **line_split, t_data *data);
void			ft_path_sprite(char **line_split, t_data *data);
void			ft_color_floor(char **line_split, t_data *data);
void			ft_color_roof(char **line_split, t_data *data);
void			ft_color(char **line_split, t_data *data, char *color);
void			ft_resolution(char **line_split, t_data *data);
int				ft_is_format(char *filename, char *extension);
int				fill_struct_parsing(char *line, t_data *data);
void			free_struct(t_data *data);
int				is_only_num_and_comma(char *str);
void			ft_error_data(char **line_split, t_data *data, char *data_str);
int				ft_is_number_str(char *str);
void			ft_print_strs(char **strs);
void			ft_print_struct(t_data data);
void			ft_check_map(t_data *data);
void			ft_check_map_characters_and_pos(char **map, t_data *data);
void			ft_check_hole_in_wall(char **map, int i, int j, t_data *data);
void			miss_element(t_data *data);
#endif
