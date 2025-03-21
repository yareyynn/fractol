#include "../inc/fractol.h"
#include <stdio.h>

void fractal_init(t_fractal *fr, char *name){
	if(!ft_strncmp(name, "mandelbrot", 11))
		fr->type = 1;
	else if(!ft_strncmp(name, "julia", 6))
		fr->type = 2;
	else if(ft_strncmp(name, "mandelbox", 10))
		fr->type = 3;
	else
	{
		ft_printf("Right arguement entry is: ./fractol <<fractal name>>\n");
		exit(1);
	}
}

int mandelbrot_calc(t_fractal *fr)
{
	double re;
	double im;
	double re_temp;
	int i;

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

int julia_calc(t_fractal *fr)
{
	double re;
	double im;
	double re_temp;
	int i;

	re = fr->shift_x;
	im = fr->shift_y;

	i = 0;
	while ((re * re + im * im) <= 4 && i++ < MAX_ITER)
	{
		re_temp = re * re - im * im - 0.70176;
		im = 2.0 * re * im + 0.3842;
		re = re_temp;
	}
	return (i);
}
