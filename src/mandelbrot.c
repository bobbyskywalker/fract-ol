/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:32:50 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/13 10:32:51 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void calculate_mandelbrot(t_frac_data *fractal)
{
    int  i;
    double x_temp;

    fractal->name = "mandelbrot";
    i = 0;
    fractal->zx = 0.0;
    fractal->zy = 0.0;
    fractal->cx = (fractal->x - (double) SCREEN_WIDTH / 2) / fractal->zoom + fractal->offset_x;
    fractal->cy = (fractal->y - (double) SCREEN_HEIGHT / 2) / fractal->zoom + fractal->offset_y;
    while (++i < fractal->max_iterations)
    {
        x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
        + fractal->cx;
        fractal->zy = 2.0 * fractal->zx * fractal->zy + fractal->cy;
        fractal->zx = x_temp;
        if (fractal->zx * fractal->zx + fractal->zy
        * fractal->zy >= 4.0)
            break ;
    }
    if (i == fractal->max_iterations)
        draw_pixel(fractal, fractal->x, fractal->y, 0x000000);
    else
        draw_pixel(fractal, fractal->x, fractal->y, (fractal->color * i) / fractal->max_iterations);
}
