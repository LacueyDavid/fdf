/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:05:32 by dlacuey           #+#    #+#             */
/*   Updated: 2023/08/01 16:53:20 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_map(int **map, int map_size)
{
	int	index;

	index = 0;
	while (index < map_size)
	{
		free(map[index]);
		index++;
	}
	free(map);
}

int	count_nb_of_lines(char *file)
{
	int		fd;
	char	*line;
	size_t	nb_of_lines;

	nb_of_lines = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		nb_of_lines++;
		line = get_next_line(fd);
	}
	close(fd);
	return (nb_of_lines);
}

int	fill_map(t_fdfmap *map, int fd)
{
	int		index;
	char	*line;
	char	**split;

	index = 0;
	while (index < map->map_size)
	{
		line = get_next_line(fd);
		if (!line)
			return (index);
		split = ft_split(line, ' ');
		free(line);
		if (!split)
			return (index);
		map->map[index] = malloc(sizeof(int) * (ft_strslen(split) + 1));
		if (!(map->map[index]))
			return (free_strs(split), index);
		map->map[index][0] = ft_strslen(split);
		ft_strs_to_ints(map->map[index], split);
		free_strs(split);
		index++;
	}
	line = get_next_line(fd);
	return (0);
}

int	check_invalide_map(t_fdfmap *map)
{
	int		index;

	index = 0;
	while (index < map->map_size)
	{
		if (map->map[index][0] != map->map[0][0])
			return (1);
		index++;
	}
	return (0);
}

int	create_map(t_fdfmap *map, char *file)
{
	int		fd;
	int		check;

	map->map_size = count_nb_of_lines(file);
	if (map->map_size == -1)
		return (1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	map->map = malloc(sizeof(int *) * map->map_size);
	if (!(map->map))
		return (1);
	check = fill_map(map, fd);
	if (check)
		return (free_map(map->map, check), 1);
	close(fd);
	if (check_invalide_map(map))
		return (free_map(map->map, map->map_size), 1);
	check_map_max(map);
	return (0);
}
