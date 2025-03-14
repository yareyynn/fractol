#include "../../inc/fractol.h"

void mandelbox(t_fractal *fractal)
{
	fractal->fractal = 2;
	fractal->x_min = -2.5;
	fractal->y_min = -1.5;
	fractal->x_max = 2.5;
	fractal->y_max = 1.5;
}