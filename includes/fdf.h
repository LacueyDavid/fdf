/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 00:26:57 by dlacuey           #+#    #+#             */
/*   Updated: 2023/08/01 09:15:46 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef WIDTH
#  define WIDTH 2560
# endif

# ifndef HEIGHT
#  define HEIGHT 1440
# endif

# ifndef BOTTOM_COLOR
#  define BOTTOM_COLOR 0x005BCEFA
# endif

# ifndef TOP_COLOR
#  define TOP_COLOR 0x00F5A9B8
# endif

# ifndef ZERO_COLOR
// #  define ZERO_COLOR 0x00FFFFFF
#  define ZERO_COLOR 0x005BCEFA
# endif

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <math.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;

typedef struct s_points
{
	t_point	p1;
	t_point	p2;
}				t_points;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_fdfmap
{
	int	**map;
	int	map_size;
	int	index;
}				t_fdfmap;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	generate_img(t_fdfmap map, t_data *img, t_vars vars);
int		count_nb_of_lines(char *file);
int		create_map(t_fdfmap *map, char *file);
int		close_window(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	print_str(char *str);
void	free_map(int **map, int map_size);
void	print_map(t_fdfmap map, t_data *img);
int		calcule_gap(t_fdfmap map);
int		get_start_y(t_fdfmap map, int gap);
int		get_start_x(t_fdfmap map, int gap);
void	rasterization(t_points points, t_data *img, int color);
void	check_map_max(t_fdfmap *map);

#endif
