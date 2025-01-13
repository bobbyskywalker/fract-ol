/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:33:00 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/13 10:33:01 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../lib/libft/libft.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/minilibx-linux/mlx_int.h"

// constants
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

// app object
typedef struct s_mlx_data
{
    void    *mlx_ptr;
    void    *window_ptr;
	void	*img_ptr;
	char	*img_addr;
} t_mlx_data;

// fractal data object
typedef struct	s_fractal_data {
    t_mlx_data *mlx_data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int            x;
	int            y;
	double         zx;
	double         zy;
	double         cx;
	double         cy;
	int            max_iterations;
	int            color;
	double         offset_x;
	double         offset_y;
	double         zoom;
	char           *name;
}   t_frac_data;


// error handlers
int	handle_args(int argc, char **argv);

// inits
void    init_fractal(t_frac_data *fractal_data);
void    init_app(t_frac_data *fractal_data);

// fractal calculations
void    calculate_mandelbrot(t_frac_data *fractal);
void    calculate_julia(t_frac_data *fractal);

// drawing utils
void	draw_pixel(t_frac_data *fractal_data, int x, int y, int color);

// highest level func
int     draw_fractal(t_frac_data *fractal, char *name);

#endif
