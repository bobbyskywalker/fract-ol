/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:32:31 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/14 15:46:47 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int argc, char **argv)
{
	t_frac_data	fractal_data;

	if (handle_args(argc, argv))
		return (1);
	init_app(&fractal_data);
	init_fractal(&fractal_data, argv);
	draw_fractal(&fractal_data);
	mlx_mouse_hook(fractal_data.mlx_data->window_ptr, mouse_controls,
		&fractal_data);
	mlx_key_hook(fractal_data.mlx_data->window_ptr, key_controls,
		&fractal_data);
	mlx_hook(fractal_data.mlx_data->window_ptr,
		17, 0, close_window, &fractal_data);
	mlx_loop(fractal_data.mlx_data->mlx_ptr);
	clean_up(&fractal_data);
}
