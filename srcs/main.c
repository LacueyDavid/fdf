/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:41:32 by dlacuey           #+#    #+#             */
/*   Updated: 2023/08/01 06:52:09 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_env(t_data *img, t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Fil de fer dlacuey");
	img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

int	main(int argc, char **argv)
{
	t_data		img;
	t_fdfmap	map;
	t_vars		vars;

	if (argc != 2)
		return (print_str("Error.\n"), 1);
	if (create_map(&map, argv[1]))
		return (print_str("Error.\n"), 1);
	init_env(&img, &vars);
	generate_img(map, &img, vars);
	free_map(map.map, map.map_size);
	mlx_destroy_image(vars.mlx, img.img);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 17, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
