/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:29:01 by udumas            #+#    #+#             */
/*   Updated: 2023/12/07 11:02:05 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	calculate_julia(t_fractal *fractal)
{
	double	i;
	double	temp;

	fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
	i = 1;
	while (i < fractal->max_iteration)
	{
		temp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * temp + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
		i = i + 1;
	}
	if (i == fractal->max_iteration)
		put_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_pixel(fractal, fractal->x, fractal->y, (fractal->color * (i * 10)));
}

void	calculate_mandelbrot(t_fractal *fractal)
{
	double	i;
	double	temp;

	fractal->cx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->cy = fractal->y / fractal->zoom + fractal->offset_y;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	i = 0;
	while (i++ < fractal->max_iteration)
	{
		temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = temp;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iteration)
		put_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_pixel(fractal, fractal->x, fractal->y, (fractal->color * (i * 10)));
}

void	calculate_burning_ship(t_fractal *fractal)
{
	int		i;
	double	temp;

	fractal->cx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->cy = fractal->y / fractal->zoom + fractal->offset_y;
	fractal->zx = fractal->cx;
	fractal->zy = fractal->cy;
	i = 0;
	while (++i < fractal->max_iteration)
	{
		temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = fabs(2. * fractal->zx * fractal->zy) + fractal->cy;
		fractal->zx = fabs(temp);
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iteration)
		put_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_pixel(fractal, fractal->x, fractal->y, (fractal->color * (i
					% 255)));
}
