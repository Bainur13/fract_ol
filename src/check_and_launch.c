/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_launch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:34:09 by udumas            #+#    #+#             */
/*   Updated: 2024/01/09 13:04:04 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	launch_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->name = "julia";
	while (fractal->x < SIZE)
	{
		fractal->y = 0;
		while (fractal->y < SIZE)
		{
			calculate_julia(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
}

void	launch_mandelbrot(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->name = "mandelbrot";
	while (fractal->x < SIZE)
	{
		fractal->y = 0;
		while (fractal->y < SIZE)
		{
			calculate_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
}

void	launch_burning_ship(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->name = "bship";
	while (fractal->x < SIZE)
	{
		fractal->y = 0;
		while (fractal->y < SIZE)
		{
			calculate_burning_ship(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
}

void	check_args(t_fractal *fractal, char *frac_name)
{
	if (ft_strncmp(frac_name, "julia", 6) == 0)
	{
		if (!fractal->cx && !fractal->cy)
		{
			fractal->cx = 0.35;
			fractal->cy = 0.767;
		}
		launch_julia(fractal);
	}
	else if (ft_strncmp(frac_name, "mandelbrot", 11) == 0)
		launch_mandelbrot(fractal);
	else if (ft_strncmp(frac_name, "bship", 6) == 0)
		launch_burning_ship(fractal);
	else
	{
		ft_putstr_fd("Invalid input\nYou should try \"./fractol\" with ", 1);
		ft_putstr_fd("either\n1.\"julia\" \n2.\"mandelbrot\"\n3.\"bship\".", 1);
		ft_putstr_fd("\nHave fun!", 1);
		exit_window(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
