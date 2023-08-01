/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_over_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:05:16 by dlacuey           #+#    #+#             */
/*   Updated: 2023/08/01 06:53:06 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_min_and_max(t_fdfmap *map, int *max_value, int *min_value)
{
	int		index;
	int		index2;

	index = 0;
	index2 = 1;
	while (index < map->map_size)
	{
		while (index2 < map->map[index][0] + 1)
		{
			if (map->map[index][index2] > *max_value)
				*max_value = map->map[index][index2];
			if (map->map[index][index2] < *min_value)
				*min_value = map->map[index][index2];
			index2++;
		}
		index2 = 1;
		index++;
	}
	if (*min_value < -HEIGHT)
	{
		*min_value += 1;
		*min_value = abs(*min_value);
	}
	if (*max_value < *min_value)
		*max_value = *min_value;
}

void	mul_if_too_small(t_fdfmap *map, int max_value)
{
	int		index;
	int		index2;

	index = 0;
	index2 = 1;
	if (max_value <= 20)
	{
		index = 0;
		index2 = 1;
		while (index < map->map_size)
		{
			while (index2 < map->map[index][0] + 1)
			{
				map->map[index][index2] *= 4;
				index2++;
			}
			index2 = 1;
			index++;
		}
	}
}

void	div_if_too_big(t_fdfmap *map, int max_value, int div)
{
	int		index;
	int		index2;

	index = 0;
	index2 = 1;
	if (max_value > HEIGHT)
	{
		index = 0;
		index2 = 1;
		while (index < map->map_size)
		{
			while (index2 < map->map[index][0] + 1)
			{
				map->map[index][index2] /= div;
				index2++;
			}
			index2 = 1;
			index++;
		}
	}
}

void	check_map_max(t_fdfmap *map)
{
	int		max_value;
	int		min_value;
	int		div;

	max_value = 0;
	min_value = 0;
	get_min_and_max(map, &max_value, &min_value);
	div = max_value / (HEIGHT / 2);
	div_if_too_big(map, max_value, div);
	mul_if_too_small(map, max_value);
}
