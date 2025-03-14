#include "fractol.h"
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