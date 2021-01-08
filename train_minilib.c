#include "mlx.h"

/* --------------- */
/* TRAIN PUT PIXEL */
/* --------------- */

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


int main()
{
    void *mlx;
    void *mlx_win;
    int i;
    int j;
    t_data img;
    int max;

    j = 0;
    max = 1;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello amigos");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.bits_per_pixel = 100;
    img.line_length = 100;
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    while (j != 100)
    {
        i = 0;
        while (i != 100)
            my_mlx_pixel_put(&img, i++, j, 0x50A832);
        j++;
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}


/* --------------- */
/*   TRAIN IMAGE   */
/* --------------- */

int main()
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
    int     img_width;
    int     img_height;

	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello amigos");
	img = mlx_xpm_file_to_image(mlx, "./image.xpm", &img_width, &img_height);
	img = mlx_png_file_to_image(mlx, "./image.png", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
   	mlx_loop(mlx);
}


/* ------------- */
/*     EVENT     */
/* ------------- */

#include <mlx.h>

typedef struct  s_vars {
        void    *mlx;
        void    *win;
}               t_vars;

int             close(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	return (1);
}

int             main(void)
{
    t_vars    vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    mlx_hook(vars.win, 2, 1L<<0, close, &vars);
    mlx_loop(vars.mlx);
	return (1);
} 