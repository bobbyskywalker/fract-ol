/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:32:52 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/13 18:03:56 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_fractal(t_frac_data *fractal_data, char *name)
{
	fractal_data->name = name;
	fractal_data->mlx_data->img_ptr = mlx_new_image
		(fractal_data->mlx_data->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	fractal_data->mlx_data->img_addr = mlx_get_data_addr(
			fractal_data->mlx_data->img_ptr,
			&fractal_data->bits_per_pixel, &fractal_data->line_length,
			&fractal_data->endian);
	fractal_data->x = 0;
	fractal_data->y = 0;
	fractal_data->offset_x = -0.5;
	fractal_data->offset_y = 0;
	fractal_data->max_iterations = 30;
	fractal_data->zoom = 300;
	fractal_data->color = 0x00F0FF;
}

void	init_app(t_frac_data *fractal_data)
{
	fractal_data->mlx_data = malloc(sizeof(t_mlx_data));
	if (!fractal_data->mlx_data)
	{
		perror("MLX initialization failure");
		exit(EXIT_FAILURE);
	}
	fractal_data->mlx_data->mlx_ptr = mlx_init();
	fractal_data->mlx_data->window_ptr = mlx_new_window(
			fractal_data->mlx_data->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT, "fract-ol");
}
