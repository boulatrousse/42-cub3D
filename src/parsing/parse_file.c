/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:51:42 by croy              #+#    #+#             */
/*   Updated: 2023/10/30 16:06:04 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Check if the file has the right extension
 *
 * @param data	pointer to the main structure
 * @param file	absolute or relative path to the file
 * @param ext	extension to check
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
int	check_extension(char *path, char *ext)
{
	int		file_len;
	int		ext_len;
	char	*file;

	file = ft_strrchr(path, '/');
	if (!file)
		file = path;
	else
		file++;
	file_len = ft_strlen(file);
	ext_len = ft_strlen(ext);
	if (file_len <= ext_len
		|| ft_strncmp(file + file_len - ext_len, ext, ext_len))
	{
		print_perr(E_EXT, file);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief Read the file and store it in a string
 *
 * @param fd		file descriptor
 * @return char*	pointer to the string containing the file
 */
char	*read_file(int fd)
{
	int		char_read;
	char	buffer[BUFFER_SIZE];
	char	*file;

	char_read = 1;
	file = NULL;
	while (char_read)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read == -1)
			return (print_perr(E_READ, NULL), NULL);
		buffer[char_read] = '\0';
		if (!file)
			file = ft_strdup(buffer);
		else
			file = ft_strjoin(file, buffer);
		if (!file && char_read)
			return (print_perr(E_MALLOC, "read_file"), NULL);
	}
	return (file);
}

/**
 * @brief Check if the file exists and store it in the t_data structure
 *
 * @param data	pointer to the main structure
 * @param path	absolute or relative path to the map file
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
int	check_file(t_data *data, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		print_perr(E_MISSING, path);
		return (EXIT_FAILURE);
	}
	{
		data->file = read_file(fd);
		if (!data->file)
		{
			close(fd);
			return (EXIT_FAILURE);
		}
	}
	close(fd);
	return (EXIT_SUCCESS);
}

/**
 * @brief Split the file into lines and store them in the t_data structure
 *
 * @param data	pointer to the main structure
 * @return int	EXIT_SUCCESS or EXIT_FAILURE
 */
int	cleanup_file(t_data *data)
{
	data->split_file = ft_split(data->file, '\n');
	if (!data->split_file)
		return (print_perr(E_MALLOC, "cleanup_file"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
