#ifndef CUB3D_H
# define CUB3D_H
# define true 1
# define false 1
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdio.h>

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
	int			w_max;
	int			h_max;
}				t_data;

typedef struct	s_ray {
	int			step[2];
	int			map[2];
	int			is_hit;
	double		eucli_dist[2];
	double		deltaDist[2];
	double		dist;
	double		rayDir[2];
	double		dir[2];
	int			side;
	double		plane[2];
	int			h_wall;
	int			draw[2];
}				t_ray;

typedef struct  s_img {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_img;

typedef struct s_window {
	void *mlx;
	void *mlx_win;
	t_img img;
}				t_window;

typedef struct	s_tab
{
	t_ray ray_data;
	t_data data;
	t_window window;
	int		is_pressed;
}				t_tab;

void			ft_parsing(int fd, t_data *data);
int				fill_struct_parsing(char *line, t_data *data);
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
void			ft_print_struct(t_ray data);
void			ft_check_map(t_data *data);
void			ft_check_map_characters_and_pos(char **map, t_data *data);
void			ft_check_hole_in_wall(char **map, int i, int j, t_data *data);
void			miss_element(t_data *data);
void			ft_raycasting(t_data data, t_ray *ray_data, t_window window);
t_ray			calculate_distance(t_data data, t_ray ray_data, int i);
void			until_wall_is_hit(t_data data, t_ray *ray_data);
void			init_step_and_eucli_dist(t_data data, t_ray *ray_data);
void			caculate_deltaDist(t_ray *ray_data);
void			calculate_max_map(t_data *data);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
void			ft_display_column(t_window window, t_ray ray_data, t_data data, int column);
void			ft_init_window(t_window *window, t_data data);
void			ft_display_raycasting(t_data data);
void			init_ray_data_before(t_ray *ray_data);
void			init_ray_data_after(t_data data, t_ray *ray_data);
int				change_color_in_hexa(char *color);
int				ft_event_pressed(int keycode, t_tab *ar_s);
int				ft_event_released(int keycode, t_tab *ar_s);
int				ft_close_window(t_tab *ar_s);
void			ft_refresh(t_tab *ar_s);
void			move(t_tab *ar_s, int moveSpeed, char op);
void			rotate(t_tab *ar_s, int rotSpeed);
#endif
