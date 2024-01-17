/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_islands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:17:46 by croy              #+#    #+#             */
/*   Updated: 2023/10/26 13:46:20 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_column_empty(t_data *data, size_t x)
{
	size_t	y;

	y = 0;
	while (data->map->array[y] && ft_strlen(data->map->array[y]) >= x)
	{
		if (data->map->array[y][x] && data->map->array[y][x] != ' ')
			return (0);
		y++;
	}
	return (1);
}

int	check_map_vert_island(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (data->map->array[y])
	{
		x = 0;
		while (data->map->array[y][x])
		{
			if (data->map->array[y][x] == ' ' && is_column_empty(data, x))
				return (print_perr(E_MAP_ISLAND, data->map->array[y]), FAILURE);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

static int	is_empty(char *line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static void	free_horizontal_island_check(int status, int fd, char *line)
{
	if (status == EXIT_FAILURE)
		print_perr(E_MAP_ISLAND, NULL);
	free(line);
	close(fd);
}

int	check_map_hori_island(t_data *data, char *path)
{
	int		status;
	int		found_map;
	int		fd;
	char	*line;

	status = EXIT_SUCCESS;
	found_map = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (print_perr(E_MISSING, path), EXIT_FAILURE);
	line = get_next_line(fd);
	if (!line)
		return (print_perr(E_MAP_MISS, NULL), EXIT_FAILURE);
	while (line)
	{
		if (!ft_strncmp(line, data->map->array[0],
				ft_strlen(data->map->array[0])))
			found_map = 1;
		if (found_map && is_empty(line))
			status = EXIT_FAILURE;
		free(line);
		line = get_next_line(fd);
	}
	free_horizontal_island_check(status, fd, line);
	return (status);
}
