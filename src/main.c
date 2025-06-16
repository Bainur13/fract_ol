/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:49:27 by udumas            #+#    #+#             */
/*   Updated: 2024/01/09 13:08:43 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#define ESC 53

int	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract_ol");
	fractal->img = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	return (0);
}

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->cx = 0;
	fractal->cy = 0;
	fractal->color = 0;
	fractal->max_iteration = 1000;
	fractal->offset_x = -2.5;
	fractal->offset_y = -2.5;
	fractal->zoom = 100;
	fractal->color = 0x4e4f14;
}

int	main(int ac, char **av)
{
	t_fractal	*fractal;

	if (ac != 2)
	{
		ft_putstr_fd("Invalid input\nYou should try \"./fractol\" with ", 1);
		ft_putstr_fd("either\n1.\"julia\" \n2.\"mandelbrot\"\n3.\"bship\".", 1);
		ft_putstr_fd("\nHave fun!", 1);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	init_mlx(fractal);
	check_args(fractal, av[1]);
	mlx_key_hook(fractal->win, key_hook, fractal);
	mlx_mouse_hook(fractal->win, mouse_hook, fractal);
	mlx_hook(fractal->win, 17, 0L, exit_window, fractal);
	mlx_loop(fractal->mlx);
	return (0);
}
