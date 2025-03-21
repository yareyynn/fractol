void render_init(t_fractal *fr)
{
    double x;
    double y;
    int color;
    int iter;

    fr->wnd.img = mlx_new_image(fr->wnd.mlx, WIDTH, HEIGHT);
    if(!fr->wnd.img)
    {
        ft_printf("Error: image is not created\n");
        close_window(fr->wnd);
        exit(1);
    }
	fr->wnd.addr = mlx_get_data_addr(fr->wnd.img, &fr->wnd.bpp, &fr->wnd.line_len, &fr->wnd.endian);
    y = 0;
    while (y++ < HEIGHT)
    {
        x = 0;
        while (x++ < WIDTH)
        {
            fr->shift_x = (double)((x - WIDTH / 2.0) * (4.0 / WIDTH));
            fr->shift_y = (double)((y - HEIGHT / 2.0) * (4.0 / HEIGHT));

            if(fr->type == 1)
                iter = mandelbrot_calc(fr);
            else if(fr->type == 2)
                iter = julia_calc(fr);
*************************************************
            color = set_color(iter);
            ft_pixel_put(wnd, x, y, 0x00FF00);
        }
    }
    fr->iter = iter;
    mlx_put_image_to_window(wnd->mlx, wnd->win, wnd->img, 0, 0);
}
