/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakarya <ysakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 07:32:37 by ysakarya          #+#    #+#             */
/*   Updated: 2025/03/28 07:36:20 by ysakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "math.h"
# include "unistd.h"
# include "stdlib.h"
# include "../../minilibx-linux/mlx.h"
# include "../../libft/libft.h"

# define MAX_ITER 50
# define WIDTH 800.0
# define HEIGHT 800.0
# define SCR_UP 4
# define SCR_DOWN 5
# define KEY_ESC 65307
# define ZOOM 1.1
# define SCALE_X 0.05
# define SCALE_Y 0.05
# define REV_X 400.0
# define REV_Y 400.0
# define KEY_L 108

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
	int				type;
	double			shift_x;
	double			shift_y;
	int				iter;
	double			mouse_x;
	double			mouse_y;
	struct s_window	wnd;
	double			zoom;
	int				lock;
}	t_fractal;

void	fractal_init(t_fractal *fr, char *name);
int		mandelbrot_calc(t_fractal *fr);
int		julia_calc(t_fractal *fr);
int		scroll_listener(int key, int x, int y, t_fractal *fr);
int		close_window(t_fractal *fr);
int		set_color(int iter);
void	ft_pixel_put(t_fractal *fr, int x, int y, int color);
void	render_init(t_fractal *fr);
void	render(t_fractal *fr);
int		mouse_move_listener(int x, int y, t_fractal *fr);
int		key_listener(int key, t_fractal *fr);
int		arg_cntl(int argc, char **argv, t_fractal *fr);
double	ft_atof(const char *str);
int		atof_cntl(char *arg);

#endif
