/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:01:34 by croy              #+#    #+#             */
/*   Updated: 2023/10/31 10:29:27 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// ========= @includes =========
# include "../mlx_linux/mlx.h"
# include "libft.h"

# include <errno.h>  // for perror
# include <fcntl.h>  // for open
# include <stdio.h>  // for printf
# include <stdlib.h> // for malloc, free, exit
# include <string.h> // for strerror
# include <unistd.h> // for close, read, write
# include <math.h>
# include "struct.h"
# include "parsing.h"
# include "exec.h"

// ========= @defines =========
# define SUCCESS	EXIT_SUCCESS
# define FAILURE	EXIT_FAILURE
# define RED		"\e[31m"
# define WHITE		"\e[37m"
# define RESET		"\e[0m"
# define BOLD		"\e[1m"
# define NO_BOLD	"\e[22m"

typedef enum e_error_code {
	E_MALLOC,
	E_READ,
	E_MISSING,
	E_EMPTY,
	E_EXT,
	E_PROP_FMT,
	E_PROP_DUP,
	E_PROP_VAR,
	E_MAP_MISS,
	E_MAP_FMT,
	E_MAP_PLYR,
	E_MAP_WALLS,
	E_MAP_ISLAND,
	E_TXT_MISS
}	t_error_code;

typedef enum e_error_exec_code {
	E_MLX_INIT,
	E_WIN_INIT,
	E_MINIMAP,
	E_IMG,
	E_ADDR,
	E_TEXTURES,
	E_PIXEL
}	t_error_exec_code;

//	===== @functions =====
// exec_free.c
void	free_mlx(t_data *data);
void	free_window(t_data *data);
void	close_fds(void);

// utils_error.c
void	print_perr(int code, char *src);
void	print_exec_err(int code, char *src);

// utils_free.c
void	free_if_alloc(char *string);
void	free_array(char **tab);
void	close_fd(int fd);
void	free_data(t_data *data);
int		map_parsing(t_data *data, char *map);

// parsing.c
int		map_parsing(t_data *data, char *map);

#endif
