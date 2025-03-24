#include "fractol.h"

int scroll_listener(int key, int x, int y, t_fractal *fr)
{
    double zoom;

    (void)x;
    (void)y;
    zoom = 1.1; // Zoom katsayısı

    if (key == 126) // MacOS Scroll Up
    {
        fr->zoom *= zoom;  // Yakınlaştır
        if (fr->iter < MAX_ITER)
            ++fr->iter;  
    }
    else if (key == 125) // MacOS Scroll Down
    {
        fr->zoom /= zoom;  // Uzaklaştır
    }

    mlx_clear_window(fr->wnd.mlx, fr->wnd.win);
    render_init(fr); // Yeniden çiz
    return (0);
}

int close_window(t_fractal *fr)
{
    mlx_destroy_image(fr->wnd.mlx, fr->wnd.img);
    mlx_destroy_window(fr->wnd.mlx, fr->wnd.win);
    exit(0);
}
