/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:32:57 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/13 18:04:07 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	draw_pixel(t_frac_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > SCREEN_WIDTH || y > SCREEN_HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->mlx_data->img_addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
