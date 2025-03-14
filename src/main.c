#include "../inc/fractol.h"
int main(int argc, char **argv){
	t_fractal fractal;
	t_window window;

	if (argc != 2)
	{
		ft_printf("Right arguement entry is: ./fractol <<fractal name>>\n");
		return (1);
	}

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 800, 800, "Fractol");

	fractal_init(&fractal, argv[1]);
	render_init(&fractal, &window);

}

void fractal_init(t_fractal *fractal, char *name)
{
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