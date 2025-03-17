#include "fractol.h"
#include <stdio.h>

int close_window(t_window *window)
{
        mlx_destroy_image(window->mlx, window->img);
        mlx_destroy_window(window->mlx, window->win);
        exit(0);
}

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

void ft_pixel_put(t_window *window, int x, int y, int color)
{
    if (!window->img)
    {
        ft_printf("Error: image is not created\n");
        close_window(window);
        exit(1);
    }
    window->addr[(y * window->line_len + x * (window->bpp / 8))] = color;
}

void render_init(t_fractal *fractal, t_window *window)
{
    double x;
    double y;
    int color;
    int iter;

    window->img = mlx_new_image(window->mlx, WIDTH, HEIGHT);
    if(!window->img)
    {
        ft_printf("Error: image is not created\n");
        close_window(window);
        exit(1);
    }
    window->addr = mlx_get_data_addr(window->img, &window->bpp, &window->line_len, &window->endian);
    y = 0;
    while (y++ < HEIGHT)
    {
        x = 0;
        while (x++ < WIDTH)
        {
            fractal->shift_x = (double)((x - WIDTH / 2.0) * (4.0 / WIDTH));
            fractal->shift_y = (double)((y - HEIGHT / 2.0) * (4.0 / HEIGHT));

            if(!ft_strncmp(fractal->name, "mandelbrot",10))
                iter = mandelbrot_calc(fractal);
            else if(!ft_strncmp(fractal->name, "julia", 5))
                iter = julia_calc(fractal);

            color = set_color(iter);
            ft_pixel_put(window, x, y, color);
        }
    }
    fractal->iter = iter;
    mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
}
