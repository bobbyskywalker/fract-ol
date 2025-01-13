#include "../inc/fractol.h"

void calculate_multibrot(t_frac_data *fractal, int power) {
    int     i;
    double  x_temp;
    double  r_squared;
    double  theta;

    fractal->name = "multibrot";
    i = 0;
    fractal->zx = 0.0;
    fractal->zy = 0.0;
    fractal->cx = (fractal->x - (double)SCREEN_WIDTH / 2) / fractal->zoom
                  + fractal->offset_x;
    fractal->cy = (fractal->y - (double)SCREEN_HEIGHT / 2) / fractal->zoom
                  + fractal->offset_y;

    while (++i < fractal->max_iterations) {
        // Convert (zx, zy) to polar coordinates
        r_squared = fractal->zx * fractal->zx + fractal->zy * fractal->zy;
        theta = atan2(fractal->zy, fractal->zx);

        // Raise Z_n to the power using polar coordinates
        double r = pow(r_squared, (double)power / 2.0);
        double angle = theta * power;

        x_temp = r * cos(angle) + fractal->cx; // Real part
        fractal->zy = r * sin(angle) + fractal->cy; // Imaginary part
        fractal->zx = x_temp;

        // Escape condition
        if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
            break;
    }

    if (i == fractal->max_iterations)
        draw_pixel(fractal, fractal->x, fractal->y, 0x000000);
    else
        draw_pixel(fractal, fractal->x, fractal->y, (fractal->color * i) / fractal->max_iterations);
}
