/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakarya <ysakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:22:31 by ysakarya          #+#    #+#             */
/*   Updated: 2025/03/28 07:31:59 by ysakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fr;

	if (!arg_cntl(argc, argv, &fr))
	{
		ft_printf("Right arguement entry is: ./fractol <<fractol name>>\n");
		ft_printf("Available fractals are: julia & mandelbrot\n");
		exit(0);
	}
	fr.wnd.mlx = mlx_init();
	if (!fr.wnd.mlx)
		return (1);
	fr.wnd.win = mlx_new_window(fr.wnd.mlx, WIDTH, HEIGHT, "Fractol");
	if (!fr.wnd.win)
		return (1);
	fractal_init(&fr, argv[1]);
	render_init(&fr);
	mlx_hook(fr.wnd.win, 17, 0, close_window, &fr);
	mlx_mouse_hook(fr.wnd.win, scroll_listener, &fr);
	mlx_key_hook(fr.wnd.win, key_listener, &fr);
	mlx_hook(fr.wnd.win, 6, 1L << 6, mouse_move_listener, &fr);
	mlx_loop(fr.wnd.mlx);
}

int	arg_cntl(int argc, char **argv, t_fractal *fr)
{
	char	*n;

	n = argv[1];
	fr->mouse_x = 0;
	fr->mouse_y = 0;
	if (argc == 4)
	{
		if (!ft_strncmp(n, "julia", 6))
		{
			if (atof_cntl(argv[2]) && atof_cntl(argv[3]))
			{
				fr->mouse_x = ft_atof(argv[2]);
				fr->mouse_y = ft_atof(argv[3]);
				return (1);
			}
		}
	}
	else if (argc == 2)
	{
		if (!ft_strncmp(n, "julia", 6) || !ft_strncmp(n, "mandelbrot", 11))
			return (1);
	}
	return (0);
}

double	ft_atof(const char *str)
{
	double	result;
	double	decimal_factor;

	decimal_factor = 1.0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			decimal_factor = -1.0;
	result = 0.0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		decimal_factor *= 10;
		str++;
	}
	return (result / decimal_factor);
}

int	atof_cntl(char *arg)
{
	int	i;
	int	flag;
	int	flag2;

	i = -1;
	flag = 0;
	flag2 = 0;
	while (arg[++i])
	{
		if (arg[i] == '.' && flag == 0)
		{
			flag = 1;
			i++;
		}
		else if ((arg[i] == '+' || arg[i] == '-') && flag2 == 0)
		{
			flag2 = 1;
			i++;
		}
		if (!ft_isdigit(arg[i]) && \
			!((arg[i] != '-' || arg[i] != '+') && flag2 == 0))
			return (0);
	}
	return (1);
}
