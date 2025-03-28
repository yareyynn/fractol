/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakarya <ysakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:18:57 by ysakarya          #+#    #+#             */
/*   Updated: 2025/03/28 05:41:05 by ysakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	set_color(int iter)
{
	int	r;
	int	g;
	int	b;

	if (iter == MAX_ITER)
		return (0x000000);
	r = (iter * 9) % 256;
	g = (iter * 2) % 256;
	b = (iter * 15) % 256;
	return ((r << 16) | (g << 8) | b);
}

void	ft_pixel_put(t_fractal *fr, int x, int y, int color)
{
	int	*p;

	if (!fr->wnd.img)
	{
		ft_printf("Error: image is not created\n");
		close_window(fr);
		exit(1);
	}
	p = (int *)(fr->wnd.addr + (y * fr->wnd.line_len + x * (fr->wnd.bpp / 8)));
	*p = color;
}

void	render_init(t_fractal *fr)
{
	fr->wnd.img = mlx_new_image(fr->wnd.mlx, WIDTH, HEIGHT);
	if (!fr->wnd.img)
	{
		ft_printf("Error: image is not created\n");
		close_window(fr);
		exit(1);
	}
	fr->wnd.addr = mlx_get_data_addr(fr->wnd.img, &fr->wnd.bpp,
			&fr->wnd.line_len, &fr->wnd.endian);
	fr->iter = 0;
	fr->zoom = 1;
	fr->lock = 1;
	render(fr);
}

void	render(t_fractal *fr)
{
	double	x;
	double	y;
	int		color;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			fr->shift_x = (double)((x - REV_X) * SCALE_X * fr->zoom);
			fr->shift_y = (double)((y - REV_Y) * SCALE_Y * fr->zoom);
			if (fr->type == 1)
				fr->iter = mandelbrot_calc(fr);
			else if (fr->type == 2)
				fr->iter = julia_calc(fr);
			color = set_color(fr->iter);
			ft_pixel_put(fr, x, y, color);
		}
	}
	mlx_put_image_to_window(fr->wnd.mlx, fr->wnd.win, fr->wnd.img, 0, 0);
}
