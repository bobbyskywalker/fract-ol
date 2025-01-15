/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:41:11 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/15 14:00:44 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	multibrot_loop(t_frac_data *fractal, t_multibrot *multibrot)
{
	int	i;

	i = 0;
	while (++i < fractal->max_iterations)
	{
		multibrot->r_squared = fractal->zx * fractal->zx + fractal->zy
			* fractal->zy;
		multibrot->theta = atan2(fractal->zy, fractal->zx);
		multibrot->r = pow(multibrot->r_squared,
				(double)fractal->multibrot_power / 2.0);
		multibrot->angle = multibrot->theta * fractal->multibrot_power;
		multibrot->x_temp = multibrot->r * cos(multibrot->angle) + fractal->cx;
		fractal->zy = multibrot->r * sin(multibrot->angle) + fractal->cy;
		fractal->zx = multibrot->x_temp;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
			break ;
	}
	return (i);
}

void	calculate_multibrot(t_frac_data *fractal)
{
	int			i;
	t_multibrot	*multibrot;

	fractal->name = "multibrot";
	multibrot = malloc(sizeof(t_multibrot));
	if (!multibrot)
		return ;
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x - (double)SCREEN_WIDTH / 2) / fractal->zoom
		+ fractal->offset_x;
	fractal->cy = (fractal->y - (double)SCREEN_HEIGHT / 2) / fractal->zoom
		+ fractal->offset_y;
	i = multibrot_loop(fractal, multibrot);
	if (i == fractal->max_iterations)
		draw_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		draw_pixel(fractal, fractal->x, fractal->y, (fractal->color * i)
			/ fractal->max_iterations);
	free(multibrot);
}
