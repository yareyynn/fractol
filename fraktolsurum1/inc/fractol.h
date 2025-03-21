#ifndef FRACTOL_H
# define FRACTOL_H

# include "math.h"
# include "unistd.h"
# include "stdlib.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define MAX_ITER 150
# define WIDTH 800
# define HEIGHT 800
# define SCR_UP 4
# define SCR_DOWN 5
# define KEY_ESC 65307

typedef struct s_fractal
{
	char	*name;
	double	zoom;
	double	shift_x;
	double	shift_y;
	int		iter;
}	t_fractal;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_window;

void fractal_init(t_fractal *fractal, char *name);
void render_init(t_fractal *fractal, t_window *window);
int mandelbrot_calc(t_fractal *fractal);
int julia_calc(t_fractal *fractal);
int close_window(t_window *window);
int set_color(int iter);
void ft_pixel_put(t_window *window, int x, int y, int color);

#endif
