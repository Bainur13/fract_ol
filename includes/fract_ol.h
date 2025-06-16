/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:15:51 by udumas            #+#    #+#             */
/*   Updated: 2023/12/07 11:26:02 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../libft/libft.h"
# include "../mlx42/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define SIZE 500

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	int		max_iteration;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;

}			t_fractal;

void		calculate_julia(t_fractal *fractal);
void		calculate_mandelbrot(t_fractal *fractal);
void		calculate_burning_ship(t_fractal *fractal);

int			key_hook(int key_code, t_fractal *fractal);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

int			exit_window(t_fractal *fractal);
void		put_pixel(t_fractal *fractal, int x, int y, int color);

void		launch_julia(t_fractal *fractal);
void		launch_mandelbrot(t_fractal *fractal);
void		launch_burning_ship(t_fractal *fractal);
void		check_args(t_fractal *fractal, char *frac_name);

void		init_fractal(t_fractal *fractal);
int			init_mlx(t_fractal *fractal);

#endif