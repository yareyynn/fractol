#include "../inc/fractol.h"
void fractal_init(t_fractal *fractal, char *name){
	fractal->zoom = 1;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	if(ft_strncmp(name, "mandelbrot", 10) == 0)
		mandelbrot(fractal);
	else if(ft_strncmp(name, "julia", 10) == 0)
		julia(fractal);
	else if(ft_strncmp(name, "mandelbox", 10) == 0)
		mandelbox(fractal);
	else
	{
		ft_printf("Right arguement entry is: ./fractol <<fractal name>>\n");
		exit(1);
	}
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

int julia_calc(t_fractal *fractal)
{
	double x;
	double y;
	double x_temp;
	double y_temp;
	double x0;
	double y0;
	int i;

	i = 0;
	while (x * x + y * y <= 4 && i < MAX_ITER)
	{
		x_temp = x * x - y * y + x0;
		y_temp = 2 * x * y + y0;
		x = x_temp;
		y = y_temp;
		i++;
	}
	return (i);
}