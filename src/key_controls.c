#include "../inc/fractol.h"

int mouse_controls(int button, int x, int y, t_frac_data *fractal)
{
    (void)x;
    (void)y;
    if (button == 4)
    {
        fractal->zoom += 10;
        if (fractal->zoom < 0.01)
            fractal->zoom = 0.01;
    }
    else if (button == 5)
    {
        fractal->zoom -= 10;
        if (fractal->zoom < 0.01)
            fractal->zoom = 0.01;
    }
    mlx_clear_window(fractal->mlx_data->mlx_ptr, fractal->mlx_data->window_ptr);
    draw_fractal(fractal);
    return (0);
}


int key_controls(int keycode, t_frac_data *fractal)
{
    if (keycode == XK_Up)
        fractal->offset_y -= 10 / fractal->zoom;
    else if (keycode == XK_Down)
        fractal->offset_y += 10 / fractal->zoom;
    else if (keycode == XK_Left)
        fractal->offset_x -= 10 / fractal->zoom;
    else if (keycode == XK_Right)
        fractal->offset_x += 10 / fractal->zoom;

    mlx_clear_window(fractal->mlx_data->mlx_ptr, fractal->mlx_data->window_ptr);
    draw_fractal(fractal);
    return (0);
}
