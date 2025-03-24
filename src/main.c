#include "../inc/fractol.h"

int main(int argc, char **argv){
	t_fractal fr;

	if (argc != 2)
	{
		ft_printf("Right arguement entry is: ./fractol <<fractol name>>\n");
		return (1);
	}

	fr.wnd.mlx = mlx_init();
	if(!fr.wnd.mlx)
	{
		ft_printf("Error: mlx_init() failed\n");
		return (1);
	}
	fr.wnd.win = mlx_new_window(fr.wnd.mlx, WIDTH, HEIGHT, "Fractol");
	if(!fr.wnd.win)
	{
		ft_printf("Error: mlx_new_window() failed\n");
		return (1);
	}

	fractal_init(&fr, argv[1]);
	fr.zoom = 1;
	render_init(&fr);
	mlx_hook(fr.wnd.win, 17, 0, close_window, &fr);
	mlx_mouse_hook(fr.wnd.win, scroll_listener, &fr);
    //mlx_key_hook(fr.wnd.win, key_listener, &fr);
	//mlx_hook(fr.wnd.win, 6, 1L << 6, mouse_move_listener, &fr);
	mlx_loop(fr.wnd.mlx);
}
