/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:32:54 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/14 11:43:12 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	handle_args(int argc, char **argv)
{
	if (argc < 2 || ((ft_strncmp(argv[1], "julia", 5)) && (ft_strncmp(argv[1],
					"multibrot", 9)) && (ft_strncmp(argv[1], "mandelbrot",
					10))))
	{
		ft_printf("valid exec: ./fractol [fractal_name]\n");
		ft_printf("fractal names: julia, mandelbrot, multibrot");
		return (1);
	}
	if (argc != 3 && (!ft_strncmp(argv[1], "julia", 5)))
	{
		ft_printf("valid exec. for julia: ./fractol julia <param_set>");
		ft_printf("available param sets: 1, 2, 3");
		return (1);
	}
	else if (argc != 3 && (!ft_strncmp(argv[1], "multibrot", 9)))
	{
		ft_printf("valid exec. for multibrot: ./fractol multibrot <power>");
		return (1);
	}
	else if ((!ft_strncmp(argv[1], "mandelbrot", 10) && argc != 2))
	{
		ft_printf("valid exec. for mandelbrot: ./fractol mandelbrot");
		return (1);
	}
	return (0);
}
