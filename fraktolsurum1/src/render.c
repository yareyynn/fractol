#include "../inc/fractol.h"
#include <stdio.h>

int set_color(int iter)
{
    int color;
    int red;
    int green;
    int blue;

    if (iter == MAX_ITER)
        return (0xFF0000);

    red = iter;
    green = iter;
    blue = iter;
    color = (red << 16) + (green << 8) + blue;

    return (color);
}

void ft_pixel_put(t_fractal *fr, int x, int y, int color)
{
    if (!fr->wnd.img)
    {
        ft_printf("Error: image is not created\n");
        close_window(fr->wnd.win);
        exit(1);
    }
    fr->wnd.addr[(y * fr->wnd.line_len + x * (fr->wnd.bpp / 8))] = color;
}

void render_init(t_fractal *fr){
    double x;
    double y;
    int color;
    int iter;

    fr->wnd.img = mlx_new_image(fr->wnd.mlx, WIDTH, HEIGHT);
    if(!fr->wnd.img)
    {
        ft_printf("Error: image is not created\n");
        close_window(fr->wnd.win);
        exit(1);
    }
    fr->wnd.addr = mlx_get_data_addr(fr->wnd.img, &fr->wnd.bpp, &fr->wnd.line_len, &fr->wnd.endian);
    y = 0;
    while (y++ < HEIGHT)
    {
        x = 0;
        while (x++ < WIDTH)
        {
            fr->shift_x = (double)((x - WIDTH / 2.0) * (4.0 / WIDTH) * fr->zoom);
            fr->shift_y = (double)((y - HEIGHT / 2.0) * (4.0 / HEIGHT) * fr->zoom);

            if(fr->type == 1)
                iter = mandelbrot_calc(fr);
            else if(fr->type == 2)
                iter = julia_calc(fr);

            color = set_color(iter);
            ft_pixel_put(fr, x, y, color);
        }
    }
    fr->iter = iter;
    mlx_put_image_to_window(fr->wnd.mlx, fr->wnd.win, fr->wnd.img, 0, 0);
}
