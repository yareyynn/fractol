#ifndef FRACTOL_H
# define FRACTOL_H

#include "math.h"
#include "unistd.h"
#include "stdlib.h"
#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include "color.h"
#include "keys.h"

typedef struct s_fractal
{
	int		fractal;
	int		max_iter;
	double	x_min;
	double	y_min;
	double	x_max;
	double	y_max;
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

# endif