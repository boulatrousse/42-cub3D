/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:12:30 by croy              #+#    #+#             */
/*   Updated: 2023/10/31 10:38:34 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Find the map's width and height and store them in the t_map structure
 *
 * @param data	pointer to the main structure
 */
static void	get_map_size(t_data *data)
{
	size_t	i;

	i = 6;
	data->map->height = ft_arrlen(data->split_file + 6);
	while (data->split_file[i])
	{
		if (ft_strlen(data->split_file[i]) > data->map->width)
			data->map->width = ft_strlen(data->split_file[i]);
		i++;
	}
}

/**
 * @brief Trims the trailing character from a string
 *
 * @param str		string to trim
 * @param c			trailing character to trim
 * @return char*	string without trailing characters (set to '\0'7)
 */
static char	*trim_trailing(char *str, char c)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (str[i] == c && i > 0)
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

/**
 * @brief Check if the map has a valid size and store it in the t_map structure
 *
 * @param data	pointer to the main structure
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
int	get_map(t_data *data)
{
	size_t	i;

	i = 0;
	if (ft_arrlen(data->split_file) <= 6 || !data->split_file[6])
		return (print_perr(E_MAP_MISS, NULL), EXIT_FAILURE);
	data->map = ft_calloc(1, sizeof(t_map));
	if (!data->map)
		return (print_perr(E_MALLOC, "get_map 1"), EXIT_FAILURE);
	get_map_size(data);
	if (data->map->width < 3 || data->map->height < 3)
		return (print_perr(E_MAP_FMT, NULL), EXIT_FAILURE);
	data->map->array = ft_calloc(data->map->height + 1, sizeof(char *));
	if (!data->map->array)
		return (print_perr(E_MALLOC, "get_map 2"), EXIT_FAILURE);
	while (i < data->map->height)
	{
		data->map->array[i] = ft_strdup(data->split_file[i + 6]);
		if (!data->map->array[i])
			return (print_perr(E_MALLOC, "get_map 3"), EXIT_FAILURE);
		data->map->array[i] = trim_trailing(data->map->array[i], ' ');
		i++;
	}
	return (EXIT_SUCCESS);
}
