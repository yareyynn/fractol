#include "fractol.h"

int close_window(int keycode, t_window *window)
{
    if (keycode == 65307)
    {
        mlx_destroy_image(window->mlx, window->img);
        mlx_destroy_window(window->mlx, window->win);
        exit(0);
    }
    else if(!window->img)
    {
        mlx_destroy_window(window->mlx, window->win);
        exit(1);
    }
    return (0);
}

int get_color(int iter)
{
    int color;
    int red;
    int green;
    int blue;

    if (iter == MAX_ITER)
        return (0x000000);

    red = (int)pow(iter, 3) % 255;
    green = (int)pow(iter, 3) % 255;
    blue = (int)pow(iter, 3) % 255;
    color = (red << 16) | (green << 8) | blue;
    return (color);
}

void ft_pixel_put(t_window *window, int x, int y, int color)
{
    window->img = mlx_new_image(window->mlx, WIDTH, HEIGHT);
    if(!window->img)
    {
        ft_printf("Error: image is not created\n");
        close_window(0, window);
        exit(1);
    }
    window->addr = mlx_get_data_addr(window->img, &window->bpp, &window->line_len, &window->endian);
}

void render_init(t_fractal *fractal, t_window *window)
{
    int x;
    int y;
    int color;
    int iter;

    y = 0;
    while (y++ < HEIGHT)
    {
        x = 0;
        while (x++ < WIDTH)
        {
            fractal->shift_x = (4 * x) / WIDTH - 2.0;
            fractal->shift_y = (4 * y) / HEIGHT - 2.0;

            if(fractal->name == "mandelbrot")
                iter = mandelbrot_calc(fractal);
            else if(fractal->name == "julia")
                iter = julia_calc(fractal);

            color = get_color(iter);

            ft_pixel_put(window, x, y, color);
        }
    }
    mlx_put_image_to_window(window->mlx, window->win, window->addr, 0, 0);
}
