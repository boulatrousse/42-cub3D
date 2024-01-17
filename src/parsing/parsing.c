/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:55:57 by croy              #+#    #+#             */
/*   Updated: 2023/10/26 13:12:32 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// #pragma GCC diagnostic ignored "-Wunused-function"
// #pragma GCC diagnostic ignored "-Wunused-variable"
//#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

static void	init_vars(t_data *data)
{
	data->file = NULL;
	data->split_file = NULL;
	data->north.path = NULL;
	data->north.fd = 0;
	data->north.img = NULL;
	data->south.path = NULL;
	data->south.fd = 0;
	data->south.img = NULL;
	data->west.path = NULL;
	data->west.fd = 0;
	data->west.img = NULL;
	data->east.path = NULL;
	data->east.fd = 0;
	data->east.img = NULL;
	data->map = NULL;
	data->floor = 0;
	data->ceiling = 0;
}

/**
 * @brief Parse and check the map file
 *
 * @param data	pointer to the main structure
 * @param map	absolute or relative path to the map
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
int	map_parsing(t_data *data, char *map)
{
	(void) data;
	init_vars(data);
	if (check_extension(map, ".cub") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_file(data, map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (cleanup_file(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (get_map(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (get_map_properties(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_map(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_map_walls(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_map_vert_island(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_map_hori_island(data, map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
