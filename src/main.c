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
	if(!window.mlx)
	{
		ft_printf("Error: mlx_init() failed\n");
		return (1);
	}
	window.win = mlx_new_window(window.mlx, WIDTH, HEIGHT, "Fractol");
	if(!window.win)
	{
		ft_printf("Error: mlx_new_window() failed\n");
		return (1);
	}

	fractal_init(&fractal, argv[1]);
	render_init(&fractal, &window);
	mlx_hook(window.win, 17, 0, close_window, &window);
	mlx_mouse_hook(window.win, scroll_listener, &fractal);
	mlx_loop(window.mlx);
}