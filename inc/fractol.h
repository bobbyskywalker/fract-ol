/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:33:00 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/14 15:46:59 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/minilibx-linux/mlx_int.h"
# include <X11/keysym.h>
# include <math.h>

// constants
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

// app object
typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*window_ptr;
	void		*img_ptr;
	char		*img_addr;
}				t_mlx_data;

// multibrot variables
typedef struct s_multibrot_data
{
	double		x_temp;
	double		r_squared;
	double		theta;
	double		r;
	double		angle;
}				t_multibrot;

// fractal data object
typedef struct s_fractal_data
{
	t_mlx_data	*mlx_data;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
	double		zx;
	double		zy;
	double		cx;
	double		cy;
	int			max_iterations;
	int			color;
	double		offset_x;
	double		offset_y;
	double		zoom;
	char		*name;
	int			julia_paramset;
	int			multibrot_power;
}				t_frac_data;

// error handlers
int				handle_args(int argc, char **argv);

// inits
void			init_fractal(t_frac_data *fractal_data, char **argv);
void			init_app(t_frac_data *fractal_data);

// fractal calculations
void			calculate_mandelbrot(t_frac_data *fractal);
void			calculate_julia(t_frac_data *fractal);
void			calculate_multibrot(t_frac_data *fractal);

// drawing utils
void			draw_pixel(t_frac_data *fractal_data, int x, int y, int color);

// highest level func
int				draw_fractal(t_frac_data *fractal);

// key hooks
int				mouse_controls(int button, int x, int y, t_frac_data *fractal);
int				key_controls(int keycode, t_frac_data *fractal);

// hud / debug
void			draw_hud_text(t_frac_data *data);

// cleanup
void			clean_up(t_frac_data *fractal_data);
int				close_window(void *param);

#endif
