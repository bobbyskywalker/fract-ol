/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:33:13 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/14 11:29:49 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	draw_fractal(t_frac_data *fractal)
{
	fractal->y = 0;
	while (fractal->y < SCREEN_HEIGHT)
	{
		fractal->x = 0;
		while (fractal->x < SCREEN_WIDTH)
		{
			if (!strncmp("mandelbrot", fractal->name, 10))
				calculate_mandelbrot(fractal);
			else if (!strncmp("julia", fractal->name, 5))
				calculate_julia(fractal);
			else if (!strncmp("multibrot", fractal->name, 9))
				calculate_multibrot(fractal);
			fractal->x++;
		}
		fractal->y++;
	}
	mlx_put_image_to_window(fractal->mlx_data->mlx_ptr,
		fractal->mlx_data->window_ptr, fractal->mlx_data->img_ptr, 0, 0);
	draw_hud_text(fractal);
	return (0);
}
