/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:32:54 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/13 10:32:55 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	handle_args(int argc, char **argv)
{
	if (argc != 2 || (ft_strncmp(argv[1], "julia", 5) && ft_strncmp(argv[1], "mandelbrot", 10)))
	{
		ft_printf("valid exec: ./fractol [fractal_name]\n");
		ft_printf("fractal names: julia, mandelbrot");
		return (1);
	}
	return (0);
}
