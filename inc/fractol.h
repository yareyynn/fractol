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
# define ZOOM 1.2

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

typedef struct s_fractal
{
	int		type;
	double	shift_x;
	double	shift_y;
	int		iter;
	double	mouse_x;
	double	mouse_y;
	struct s_window wnd;
}	t_fractal;

void fractal_init(t_fractal *fr, char *name);
int mandelbrot_calc(t_fractal *fr);
int julia_calc(t_fractal *fr);

#endif
