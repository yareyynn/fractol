#include "../inc/fractol.h"

int scroll_listener(int key, int x, int y, t_fractal *fr)
{
    (void)x;
    (void)y;

    if (key == 126)
        fr->zoom *= ZOOM;
    else if (key == 125)
        fr->zoom /= ZOOM;
    render_init(fr);
    return 0;
}

int close_window(t_fractal *fr)
{
        mlx_destroy_image(fr->wnd.mlx, fr->wnd.img);
        mlx_destroy_window(fr->wnd.mlx, fr->wnd.win);
        exit(0);
}
