/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:39:14 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/14 11:41:30 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_cx(t_frac_data *fractal)
{
	if (fractal->julia_paramset == 1)
		fractal->cx = -0.7;
	else if (fractal->julia_paramset == 2)
		fractal->cx = 0.285;
	else if (fractal->julia_paramset == 3)
		fractal->cx = 0.355;
	else
		fractal->cx = -0.8;
}

void	init_cy(t_frac_data *fractal)
{
	if (fractal->julia_paramset == 1)
		fractal->cy = 0.27015;
	else if (fractal->julia_paramset == 2)
		fractal->cy = 0.01;
	else if (fractal->julia_paramset == 3)
		fractal->cy = 0.355;
	else
		fractal->cy = 0.156;
}

void	calculate_julia(t_frac_data *fractal)
{
	int		i;
	double	x_temp;

	fractal->name = "julia";
	i = 0;
	fractal->zx = (fractal->x - (double)SCREEN_WIDTH / 2) / fractal->zoom
		+ fractal->offset_x;
	fractal->zy = (fractal->y - (double)SCREEN_HEIGHT / 2) / fractal->zoom
		+ fractal->offset_y;
	init_cx(fractal);
	init_cy(fractal);
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2.0 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
			break ;
	}
	if (i == fractal->max_iterations)
		draw_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		draw_pixel(fractal, fractal->x, fractal->y, (fractal->color * i)
			/ fractal->max_iterations);
}
