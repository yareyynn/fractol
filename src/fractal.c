#include "fractol.h"
void fractal_init(void *fractal, char *name)
{
	fractal->type = 0;
	fractal->max_iter = 50;
	fractal->zoom = 1;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal_val(fractal, name);
}

void fractal_val(void *fractal, char *name)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
	{
		fractal->x_min = -2.5;
		fractal->y_min = -1.5;
		fractal->x_max = 2.5;
		fractal->y_max = 1.5;
	}
	else if (strcmp(name, "julia") == 0)
	{
		fractal->type = 1;
		fractal->x_min = -2.5;
		fractal->y_min = -1.5;
		fractal->x_max = 2.5;
		fractal->y_max = 1.5;
	}
	else if (strcmp(name, "mandelbox") == 0)
	{
		fractal->x_min = -2.5;
		fractal->y_min = -1.5;
		fractal->x_max = 2.5;
		fractal->y_max = 1.5;
	}
	else
	{
		ft_printf("Right arguement entry is: ./fractol <<fractal name>>\n");
		exit(1);
	}
}