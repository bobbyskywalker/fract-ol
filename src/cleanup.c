/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:43:37 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/15 14:00:53 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	clean_up(t_frac_data *fractal_data)
{
	if (fractal_data->mlx_data->img_ptr)
	{
		mlx_destroy_image(fractal_data->mlx_data->mlx_ptr,
			fractal_data->mlx_data->img_ptr);
	}
	if (fractal_data->mlx_data->window_ptr)
	{
		mlx_destroy_window(fractal_data->mlx_data->mlx_ptr,
			fractal_data->mlx_data->window_ptr);
	}
	if (fractal_data->mlx_data->mlx_ptr)
	{
		mlx_destroy_display(fractal_data->mlx_data->mlx_ptr);
		free(fractal_data->mlx_data->mlx_ptr);
	}
	free(fractal_data->mlx_data);
}

int	close_window(void *param)
{
	clean_up(param);
	exit(0);
}
