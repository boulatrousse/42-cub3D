/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:56:47 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/30 13:43:22 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	launcher_minimap(t_data *data, int size_map);
static void	draw_squares(t_mlx_data *minimap, int color, \
	t_vector_int pos, int size_map);

void	draw_minimap(t_data *data)
{
	int		size_map;

	size_map = 20;
	if (data->map->height > 50 || data->map->width > 50)
		size_map /= 5;
	else if (data->map->height > 30 || data->map->width > 30)
		size_map /= 2;
	launcher_minimap(data, size_map);
	draw_player_minimap(&data->minimap, data->player_pos.x, \
		data->player_pos.y, size_map);
}

static void	launcher_minimap(t_data *data, int size_map)
{
	t_vector_int	pos;

	pos.x = 0;
	pos.y = 0;
	while (data->map->array[pos.x])
	{
		pos.y = 0;
		while (data->map->array[pos.x][pos.y])
		{
			if (data->map->array[pos.x][pos.y] == '1')
				draw_squares(&data->minimap, MAP_WALL, pos, size_map);
			else if (ft_strchr("NSWE0", data->map->array[pos.x][pos.y]))
				draw_squares(&data->minimap, MAP_SPACE, pos, size_map);
			pos.y++;
		}
		pos.x++;
	}
}

static void	draw_squares(t_mlx_data *minimap, int color, \
	t_vector_int pos, int size_map)
{
	int	i;
	int	j;

	i = pos.x * size_map;
	j = pos.y * size_map;
	while (i < (pos.x * size_map) + size_map)
	{
		j = pos.y * size_map;
		while (j < (pos.y * size_map) + size_map)
		{
			put_pixel(minimap, j, i, color);
			j++;
		}
		i++;
	}
}
