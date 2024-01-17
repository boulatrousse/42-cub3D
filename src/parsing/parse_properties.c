/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_properties.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:14:39 by croy              #+#    #+#             */
/*   Updated: 2023/10/30 17:19:15 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Store the texture's path and file descriptor in the t_texture structure
 *
 * @param texture	pointer to the t_texture structure to store the data in
 * @param path		absolute or relative path to the texture file
 * @return int		EXIT_SUCCESS or EXIT_FAILURE
 */
static int	set_texture(t_texture *texture, char *path)
{
	if (texture->fd > 0)
		return (print_perr(E_PROP_DUP, path), EXIT_FAILURE);
	texture->path = ft_strdup(path);
	if (!texture->path)
		return (print_perr(E_MALLOC, "set_texture"), EXIT_FAILURE);
	texture->fd = open(path, O_RDONLY);
	if (texture->fd == -1)
		return (print_perr(E_TXT_MISS, path), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * @brief Check if the string only contains digits
 *
 * @param str	string to check
 * @return int	1 if the string only contains digits, 0 otherwise
 */
static int	ft_isonlydigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Convert the RGB floor and ceiling colors to hexadecimal
 *
 * @param color	pointer to the color converted to hexadecimal
 * @param input	string containing the RGB values separated by commas
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
static int	set_color(unsigned int *color, char *input)
{
	int		i;
	int		rgb[3];
	char	**colors;

	i = 0;
	if (ft_countchar(input, ',') != 2)
		return (print_perr(E_PROP_FMT, input), FAILURE);
	colors = ft_split(input, ',');
	if (!colors)
		return (print_perr(E_MALLOC, "get_color"), EXIT_FAILURE);
	if (ft_arrlen(colors) != 3)
		return (print_perr(E_PROP_FMT, input), free_array(colors), FAILURE);
	while (colors[i])
	{
		if (!ft_isonlydigit(colors[i]))
			return (print_perr(E_PROP_FMT, input), free_array(colors), FAILURE);
		rgb[i] = ft_atoi(colors[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (print_perr(E_PROP_FMT, input), free_array(colors), FAILURE);
		i++;
	}
	free_array(colors);
	*color = rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	return (EXIT_SUCCESS);
}

/**
 * @brief Parse the map's properties and store them in the t_data structure
 *
 * @param data	pointer to the main structure
 * @param lines	array containing the property's name and value
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
static	int	get_texture(t_data *data, char **lines)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (!ft_strcmp(lines[0], "NO"))
		exit_code = set_texture(&data->north, lines[1]);
	else if (!ft_strcmp(lines[0], "SO"))
		exit_code = set_texture(&data->south, lines[1]);
	else if (!ft_strcmp(lines[0], "WE"))
		exit_code = set_texture(&data->west, lines[1]);
	else if (!ft_strcmp(lines[0], "EA"))
		exit_code = set_texture(&data->east, lines[1]);
	else if (!ft_strcmp(lines[0], "F"))
		exit_code = set_color(&data->floor, lines[1]);
	else if (!ft_strcmp(lines[0], "C"))
		exit_code = set_color(&data->ceiling, lines[1]);
	else
	{
		exit_code = EXIT_FAILURE;
		print_perr(E_PROP_VAR, lines[0]);
	}
	return (exit_code);
}

/**
 * @brief Dispatch the map's properties to the right functions to be stored,
 * also check if the properties are valid
 *
 * @param data	pointer to the main structure
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
int	get_map_properties(t_data *data)
{
	int		i;
	char	**lines;

	i = 0;
	while (data->split_file && i < 6)
	{
		lines = ft_split(data->split_file[i], ' ');
		if (!lines)
			return (print_perr(E_MALLOC, "get_map_properties"), EXIT_FAILURE);
		if (ft_arrlen(lines) != 2 || ft_isdigit(lines[0][0]))
		{
			print_perr(E_PROP_FMT, lines[0]);
			free_array(lines);
			return (EXIT_FAILURE);
		}
		if (get_texture(data, lines) == EXIT_FAILURE)
			return (free_array(lines), EXIT_FAILURE);
		free_array(lines);
		i++;
	}
	return (EXIT_SUCCESS);
}
