/*#include "fractol.h"

int scroll_listener(int key, int x, int y, t_fractal *fractal)
{
    double zoom;

    zoom = 1.1;

    if (key == SCR_UP)
    {
        fractal->shift_x = (x / fractal->zoom + fractal->shift_x) - (x / (fractal->zoom * zoom));
        fractal->shift_y = (y / fractal->zoom + fractal->shift_y) - (y / (fractal->zoom * zoom));
        fractal->zoom *= zoom;
        if (fractal->iter < MAX_ITER)
            ++fractal->iter;
    }
    else if (key == SCR_DOWN)
    {
        fractal->shift_x = (x / fractal->zoom + fractal->shift_x) - (x / (fractal->zoom / zoom));
        fractal->shift_y = (y / fractal->zoom + fractal->shift_y) - (y / (fractal->zoom / zoom));
        fractal->zoom /= zoom;
    }
    //render_init(fractal, window);
    return (0);
}
*/