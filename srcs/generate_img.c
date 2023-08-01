/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:04:36 by dlacuey           #+#    #+#             */
/*   Updated: 2023/08/01 06:52:46 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	calcule_gap(t_fdfmap map)
{
	int	gap;
	int	lines_add_lengh;

	gap = 0;
	lines_add_lengh = map.map_size + map.map[0][0];
	gap = (HEIGHT) / lines_add_lengh;
	if (gap < 4)
		gap = 4;
	return (gap);
}

int	get_start_y(t_fdfmap map, int gap)
{
	float	vector;
	float	y1;
	float	y2;
	float	line_lengh;
	float	deg;

	deg = (30 * M_PI) / 180;
	line_lengh = (float)map.map_size * (float)gap;
	y1 = fabs(sqrt(pow(line_lengh, 2) - pow(line_lengh * cos(deg), 2)));
	y2 = fabs(sin(deg) * (float)map.map[map.map_size - 1][0] * (float)gap);
	vector = ((float)HEIGHT / 2) - ((y1 + y2) / 2);
	vector = roundf(vector);
	return ((int)vector);
}

int	get_start_x(t_fdfmap map, int gap)
{
	float	vector;
	float	line_lengh;
	float	x1;
	float	x2;
	float	deg;

	deg = (30 * M_PI) / 180;
	line_lengh = (float)map.map_size * (float)gap;
	x1 = fabs(line_lengh * cos(deg));
	x2 = fabs(cos(deg) * (float)gap * (float)map.map[map.map_size - 1][0]);
	if (x1 > x2)
		vector = (float)WIDTH / 2 + ((x1 - x2) / 2);
	else
		vector = (float)WIDTH / 2 - ((x2 - x1) / 2);
	vector = roundf(vector);
	return ((int)vector);
}

void	generate_img(t_fdfmap map, t_data *img, t_vars vars)
{
	print_map(map, img);
	mlx_put_image_to_window(vars.mlx, vars.win, img->img, 0, 0);
}
