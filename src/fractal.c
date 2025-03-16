#include "../inc/fractol.h"
void fractal_init(t_fractal *fractal, char *name){
	int i;

	fractal->zoom = 1.1;

	i = 0;
	if(ft_strncmp(name, "mandelbrot", 10) == 0)
		fractal->name = "mandelbrot";
	else if(ft_strncmp(name, "julia", 10) == 0)
		fractal->name = "julia";
	else if(ft_strncmp(name, "mandelbox", 10) == 0)
		fractal->name = "mandelbox";
	else
	{
		ft_printf("Right arguement entry is: ./fractol <<fractal name>>\n");
		exit(1);
	}
}

int mandelbrot_calc(t_fractal *fractal)
{
	double re;
	double im;
	double re_temp;
	int i;

	re = 0;
	im = 0;

	i = 0;
	while ((re * re + im * im) <= 4 && i++ < MAX_ITER)
	{
		re_temp = re * re - im * im + fractal->shift_x;
		im = 2.0 * re * im + fractal->shift_y;
		re = re_temp;
	}
	return (i);
}

int julia_calc(t_fractal *fractal)
{
	double re;
	double im;
	double re_temp;
	int i;

	re = fractal->shift_x;
	im = fractal->shift_y;

	i = 0;
	while ((re * re + im * im) <= 4 && i++ < MAX_ITER)
	{
		re_temp = re * re - im * im - 0.70176;
		im = 2.0 * re * im + 0.3842;
		re = re_temp;
	}
	return (i);
}
