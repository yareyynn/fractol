int scroll_listener(int key, int x, int y, t_fractal *fr)
{
    static int zoom;

    zoom = ZOOM;
    fr->mouse_x = (x - WIDTH / 2) / zoom + fr->shift_x;
    fr->mouse_y = (y - HEIGHT / 2) / zoom + fr->shift_y;

    if (key == 4)
        zoom *= ZOOM;
    else if (key == 5)

}
