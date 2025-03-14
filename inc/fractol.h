#ifndef FRACTOL_H
# define FRACTOL_H

#include "math.h"
#include "unistd.h"
#include "stdlib.h"
#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include "color.h"
#include "keys.h"

# define MAX_ITER 50

typedef_struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractal
{
	double	zoom;
	double	shift_x;
	double	shift_y;
}	t_fractal;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp; // bits per pixel
	int		line_len;
	int		endian;
}	t_window;

void fractal_init(t_fractal *fractal, char *name);
void fractal_val(t_fractal *fractal, char *name);
void render_init(t_fractal *fractal, t_window *window);

# endif