#ifndef STRUCT_H
#define STRUCT_H

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
	double		pos_player[2];
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
	double		step_tex_x;
	double		step_tex_y;
	double		wallx;
	int			texx;
	int			texy;
	double		step_tex;
	double		texpos;
}				t_ray;

typedef struct  s_img {
	void        *img;
	int			*addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
	int			width;
	int			height;
}               t_img;

typedef struct s_window {
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	t_img		n_texture;
	t_img		s_texture;
	t_img		e_texture;
	t_img		w_texture;
	t_img		*texture_used;
}				t_window;

typedef struct	s_key
{
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_a;
	int			key_up;
	int			key_down;
	int			key_left;
	int			key_right;
}				t_key;

typedef struct	s_tab
{
	t_ray ray_data;
	t_data data;
	t_window window;
	t_key	key;
}				t_tab;
#endif