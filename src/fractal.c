/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakarya <ysakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:32:34 by ysakarya          #+#    #+#             */
/*   Updated: 2025/03/24 21:32:35 by ysakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	fractal_init(t_fractal *fr, char *name)
{
	if (!ft_strncmp(name, "mandelbrot", 11))
		fr->type = 1;
	else if (!ft_strncmp(name, "julia", 6))
		fr->type = 2;
	else
	{
		ft_printf("Right arguement entry is: ./fractol <<fractol name>>\n");
		ft_printf("Available fractals are: julia & mandelbrot\n");
		mlx_destroy_window(fr->wnd.mlx, fr->wnd.win);
		mlx_destroy_display(fr->wnd.mlx);
		free(fr->wnd.mlx);
		exit(0);
	}
}

int	mandelbrot_calc(t_fractal *fr)
{
	double	re;
	double	im;
	double	re_temp;
	int		i;

	re = 0.0;
	im = 0.0;
	i = 0;
	while ((re * re + im * im) <= 4 && i++ < MAX_ITER)
	{
		re_temp = re * re - im * im + fr->shift_x;
		im = 2.0 * re * im + fr->shift_y;
		re = re_temp;
	}
	return (i);
}

int	julia_calc(t_fractal *fr)
{
	double	re;
	double	im;
	double	re_temp;
	int		i;

	re = fr->shift_x;
	im = fr->shift_y;
	i = 0;
	while ((re * re + im * im) <= 4 && i++ < MAX_ITER)
	{
		re_temp = re * re - im * im + fr->mouse_x;
		im = 2.0 * re * im + fr->mouse_y;
		re = re_temp;
	}
	return (i);
}
