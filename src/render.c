#include "../inc/fractol.h"

int set_color(int iter)
{
    if (iter == MAX_ITER)
        return (0x000000); // Siyah (Maksimum iterasyonda)

    int r = (iter * 9) % 256;
    int g = (iter * 2) % 256;
    int b = (iter * 15) % 256;

    return ((r << 16) | (g << 8) | b);
}

void ft_pixel_put(t_fractal *fr, int x, int y, int color)
{
    if (!fr->wnd.img)
    {
        ft_printf("Error: image is not created\n");
        close_window(fr);
        exit(1);
    }
    int *pixel = (int *)(fr->wnd.addr + (y * fr->wnd.line_len + x * (fr->wnd.bpp / 8)));
    *pixel = color;

}

void render_init(t_fractal *fr)
{
    fr->wnd.img = mlx_new_image(fr->wnd.mlx, WIDTH, HEIGHT);
    if(!fr->wnd.img)
    {
        ft_printf("Error: image is not created\n");
        close_window(fr);
        exit(1);
    }
	fr->wnd.addr = mlx_get_data_addr(fr->wnd.img, &fr->wnd.bpp, &fr->wnd.line_len, &fr->wnd.endian);
    fr->mouse_x = 0;
    fr->mouse_y = 0;
    fr->iter = 0;
    render(fr);
}

void render(t_fractal *fr)
{
    double x;
    double y;
    int color;

    y = 0;
    while (y++ < HEIGHT)
    {
        x = 0;
        while (x++ < WIDTH)
        {
            fr->shift_x = (double)((x - WIDTH / 2.0) * SCALE_X * fr->zoom);
            fr->shift_y = (double)((y - HEIGHT / 2.0) * SCALE_Y * fr->zoom);
            if(fr->type == 1)
                fr->iter = mandelbrot_calc(fr);
            else if(fr->type == 2)
                fr->iter = julia_calc(fr);
            color = set_color(fr->iter);
            ft_pixel_put(fr, x, y, color);
        }
    }
    mlx_put_image_to_window(fr->wnd.mlx, fr->wnd.win, fr->wnd.img, 0, 0);
}
