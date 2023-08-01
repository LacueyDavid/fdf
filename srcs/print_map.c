/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 04:24:48 by dlacuey           #+#    #+#             */
/*   Updated: 2023/08/01 07:03:35 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	def_col(int z1, int z2)
{
	int		color;

	if (z1 > 0 || z2 > 0)
		color = TOP_COLOR;
	else if (z1 < 0 || z2 < 0)
		color = BOTTOM_COLOR;
	else
		color = ZERO_COLOR;
	return (color);
}

void	print_line_x(int gap, t_point start_point, int *line, t_data *img)
{
	t_points	points;
	int			index;
	float		deg;
	int			col;

	deg = (30 * M_PI) / 180;
	points.p2.x = start_point.x + (int)round((cos(deg) * (float)gap));
	points.p2.y = start_point.y + (int)fabs(round(sin(deg) * (float)gap));
	points.p1 = start_point;
	index = 1;
	while (index < line[0])
	{
		points.p1.z = points.p1.y - (line[index]);
		points.p2.z = points.p2.y - (line[index + 1]);
		col = def_col(line[index], line[index + 1]);
		rasterization(points, img, col);
		points.p1.x += (int)round((cos(deg) * (float)gap));
		points.p1.y += (int)fabs(round(sin(deg) * (float)gap));
		points.p2.x += (int)round((cos(deg) * (float)gap));
		points.p2.y += (int)fabs(round(sin(deg) * (float)gap));
		index++;
	}
}

void	print_line_y(int gap, t_point start_point, t_fdfmap map, t_data *img)
{
	t_points	points;
	int			index;
	float		deg;
	int			col;

	deg = (30 * M_PI) / 180;
	points.p2.x = start_point.x - (int)round((cos(deg) * (float)gap));
	points.p2.y = start_point.y + (int)fabs(round(sin(deg) * (float)gap));
	points.p1 = start_point;
	index = 0;
	while (index < map.map_size - 1)
	{
		points.p1.z = points.p1.y - (map.map[index][map.index]);
		points.p2.z = points.p2.y - (map.map[index + 1][map.index]);
		col = def_col(map.map[index][map.index], map.map[index + 1][map.index]);
		rasterization(points, img, col);
		points.p1.x -= (int)round((cos(deg) * (float)gap));
		points.p1.y += (int)fabs(round(sin(deg) * (float)gap));
		points.p2.x -= (int)round((cos(deg) * (float)gap));
		points.p2.y += (int)fabs(round(sin(deg) * (float)gap));
		index++;
	}
}

void	print_lines_y(t_fdfmap map, t_data *img)
{
	int		gap;
	t_point	start_point;
	float	deg;

	deg = (30 * M_PI) / 180;
	gap = calcule_gap(map);
	map.index = 1;
	start_point.x = get_start_x(map, gap);
	start_point.y = get_start_y(map, gap);
	while (map.index <= map.map[0][0])
	{
		print_line_y(gap, start_point, map, img);
		start_point.x += (int)round((cos(deg) * (float)gap));
		start_point.y += (int)fabs(round(sin(deg) * (float)gap));
		map.index++;
	}
}

void	print_map(t_fdfmap map, t_data *img)
{
	int		gap;
	t_point	start_point;
	int		index;
	float	deg;

	deg = (30 * M_PI) / 180;
	index = 0;
	gap = calcule_gap(map);
	start_point.x = get_start_x(map, gap);
	start_point.y = get_start_y(map, gap);
	while (index < map.map_size)
	{
		print_line_x(gap, start_point, map.map[index], img);
		start_point.x -= (int)round((cos(deg) * (float)gap));
		start_point.y += (int)fabs(round(sin(deg) * (float)gap));
		index++;
	}
	print_lines_y(map, img);
}
