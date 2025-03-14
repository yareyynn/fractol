#include "../../inc/fractol.h"

void mandelbrot(t_fractal *fractal)
{
	fractal->fractal = 2;
	fractal->zoom = 1;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
}

int mandelbrot_calc(t_fractal *fractal)
{
	double x;
	double y;
	double x_temp;
	double y_temp;
	double x0;
	double y0;
	int i;

	x = 0;
	y = 0;
	x0 = 0;
	y0 = 0;
	i = 0;
	while (x * x + y * y <= 4 && i < MAX_ITER)
	{
		x_temp = x * x - y * y + x0;
		y_temp = 2 * x * y + y0;
		x = x_temp;
		i++;
	}
	return (i);
}
