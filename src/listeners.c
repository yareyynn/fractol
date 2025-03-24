/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listeners.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakarya <ysakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:30:40 by ysakarya          #+#    #+#             */
/*   Updated: 2025/03/24 21:30:41 by ysakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	scroll_listener(int key, int x, int y, t_fractal *fr)
{
	(void)x;
	(void)y;
	if (key == SCR_UP)
	{
		fr->zoom *= ZOOM;
		render(fr);
	}
	else if (key == SCR_DOWN)
	{
		fr->zoom /= ZOOM;
		render(fr);
	}
	return (0);
}

int	close_window(t_fractal *fr)
{
	if (fr->wnd.img)
		mlx_destroy_image(fr->wnd.mlx, fr->wnd.img);
	if (fr->wnd.win)
		mlx_destroy_window(fr->wnd.mlx, fr->wnd.win);
	mlx_destroy_display(fr->wnd.mlx);
	free(fr->wnd.mlx);
	exit (0);
}

int	mouse_move_listener(int x, int y, t_fractal *fr)
{
	if (fr->type == 2)
	{
		fr->mouse_x = (double)((x - REV_X) * SCALE_X);
		fr->mouse_y = (double)((y - REV_Y) * SCALE_Y);
		render(fr);
	}
	return (0);
}

int	key_listener(int key, t_fractal *fr)
{
	if (key == KEY_ESC)
		close_window(fr);
	return (0);
}
