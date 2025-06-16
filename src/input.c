/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:30:26 by udumas            #+#    #+#             */
/*   Updated: 2023/12/05 18:35:13 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	proportional_zoom(int i, int x, int y, t_fractal *fractal)
{
	double	vision;

	vision = 1.42;
	if (i == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * vision));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * vision));
		fractal->zoom *= vision;
	}
	else if (i == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / vision));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / vision));
		fractal->zoom /= vision;
	}
	else
		return ;
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == 4)
		proportional_zoom(1, x, y, fractal);
	else if (mouse_code == 5)
		proportional_zoom(-1, x, y, fractal);
	check_args(fractal, fractal->name);
	return (0);
}

void	random_generation(t_fractal *fractal)
{
	fractal->cx = (double)rand() / RAND_MAX;
	fractal->cy = (double)rand() / RAND_MAX;
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == XK_Escape)
		exit_window(fractal);
	if (key_code == XK_Left)
		fractal->offset_x -= 30 / fractal->zoom;
	if (key_code == XK_Right)
		fractal->offset_x += 30 / fractal->zoom;
	if (key_code == XK_Up)
		fractal->offset_y -= 30 / fractal->zoom;
	if (key_code == XK_Down)
		fractal->offset_y += 30 / fractal->zoom;
	if (key_code == XK_g)
		random_generation(fractal);
	if (key_code == XK_r)
		fractal->color = rand() % 255;
	check_args(fractal, fractal->name);
	return (0);
}
