/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:01:34 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/14 15:46:26 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	mouse_controls(int button, int x, int y, t_frac_data *fractal)
{
	double	mouse_real;
	double	mouse_imag;

	mouse_real = (x - (double)SCREEN_WIDTH / 2) / fractal->zoom
		+ fractal->offset_x;
	mouse_imag = (y - (double)SCREEN_HEIGHT / 2) / fractal->zoom
		+ fractal->offset_y;
	if (button == 4)
		fractal->zoom *= 1.1;
	else if (button == 5)
		fractal->zoom /= 1.1;
	if (fractal->zoom > 300000000.0 || fractal->zoom < 0.500000)
	{
		printf("extreme zoom level: zoom set back to default");
		fractal->zoom = 300;
	}
	fractal->offset_x = mouse_real - (x - (double)SCREEN_WIDTH / 2)
		/ fractal->zoom;
	fractal->offset_y = mouse_imag - (y - (double)SCREEN_HEIGHT / 2)
		/ fractal->zoom;
	mlx_clear_window(fractal->mlx_data->mlx_ptr, fractal->mlx_data->window_ptr);
	draw_fractal(fractal);
	return (0);
}

void	shift_color(t_frac_data *fractal)
{
	int	red;
	int	green;
	int	blue;
	int	step;

	red = (fractal->color >> 16) & 0xFF;
	green = (fractal->color >> 8) & 0xFF;
	blue = fractal->color & 0xFF;
	step = 10;
	if (red >= 255 && green < 255 && blue == 0)
		green += step;
	else if (green >= 255 && red > 0)
		red -= step;
	else if (green >= 255 && blue < 255)
		blue += step;
	else if (blue >= 255 && green > 0)
		green -= step;
	else if (blue >= 255 && red < 255)
		red += step;
	else if (red >= 255 && blue > 0)
		blue -= step;
	fractal->color = (red << 16) | (green << 8) | blue;
}

int	key_controls(int keycode, t_frac_data *fractal)
{
	if (keycode == XK_Up)
		fractal->offset_y -= 10 / fractal->zoom;
	else if (keycode == XK_Down)
		fractal->offset_y += 10 / fractal->zoom;
	else if (keycode == XK_Left)
		fractal->offset_x -= 10 / fractal->zoom;
	else if (keycode == XK_Right)
		fractal->offset_x += 10 / fractal->zoom;
	else if (keycode == XK_space)
		shift_color(fractal);
	else if (keycode == XK_Escape)
	{
		clean_up(fractal);
		exit(0);
	}
	mlx_clear_window(fractal->mlx_data->mlx_ptr, fractal->mlx_data->window_ptr);
	draw_fractal(fractal);
	return (0);
}

void	draw_hud_text(t_frac_data *data)
{
	ft_printf("zoom level: %d\n", (int)data->zoom);
}
