/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 06:43:14 by dlacuey           #+#    #+#             */
/*   Updated: 2023/08/01 06:53:19 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_point	define_direction(t_points points)
{
	t_point	direction;

	if (points.p1.x < points.p2.x)
		direction.x = 1;
	else
		direction.x = -1;
	if (points.p1.z < points.p2.z)
		direction.y = 1;
	else
		direction.y = -1;
	return (direction);
}

void	rasterization(t_points points, t_data *img, int color)
{
	int		error;
	int		err2;
	t_point	diff;
	t_point	direction;

	direction = define_direction(points);
	diff.x = abs(points.p2.x - points.p1.x);
	diff.y = -abs(points.p2.z - points.p1.z);
	error = diff.x + diff.y;
	while (points.p1.x != points.p2.x || points.p1.z != points.p2.z)
	{
		my_mlx_pixel_put(img, points.p1.x, points.p1.z, color);
		err2 = 2 * error;
		if (err2 >= diff.y)
		{
			error += diff.y;
			points.p1.x += direction.x;
		}
		if (err2 <= diff.x)
		{
			error += diff.x;
			points.p1.z += direction.y;
		}
	}
}
