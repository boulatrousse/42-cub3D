/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:34:12 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/30 15:28:25 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "cub3d.h"
# include "struct.h"

# define SUCCESS		EXIT_SUCCESS
# define FAILURE		EXIT_FAILURE
# define IMG_ERR		1

// ===== Define Keys =====
# define KEY_ESC		65307
# define LEFT_ARROW		65361
# define RIGHT_ARROW	65363
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

// ===== Game define =====
# define BLOCK			20
# define SIZE_MAP		20
# define PRINT_MAP		10
# define SIZE_WALL		125
# define SIZE_CUT		4
# define EYE_SIGHT		540
# define TOL			0.025
# define MIN_LEN_RAY	0.0886
# define HEIGHT			1080
# define WIDTH			1920
# define WALL_H			1800

// ===== Maths define =====
# define PI				3.1415926535
# define RAD			0.0174533

// ===== Colors minimap =====
# define MAP_WALL		0x0f056b
# define MAP_SPACE		0x919191
# define MAP_PLAYER		0x00ff7f

// ========== Exec ==========
int		exec_manager(t_data *data);
void	ft_dda(t_data *data, t_ray *ray, t_vector_float direction);
int		close_window(t_data *data, int status);

// ========== Init ==========
int		init_mlx(t_data *data);
int		init_textures(t_data *data);
void	init_player(t_data *data, char **map);
void	init_ray_struct(t_data *data, t_ray *ray, \
			float dir_x, float dir_y);

// ========== Draw ==========
void	draw_minimap(t_data *data);
void	draw_player_minimap(t_mlx_data *minimap, \
			float x, float y, int size_map);
void	draw_walls(t_data *data, t_ray *ray, int width, float angle);
char	*draw_textures(t_data *data, t_ray *ray, int y);
int		refresh_window(t_data *data);

// ========== Moves ==========
int		moves(int key_code, t_data *data);
void	rotation(t_data *data, int key);

// ========== Raycasting ==========
void	raycasting(t_data *data);

// ========== Utils ===========
void	put_pixel(t_mlx_data *data, int x, int y, int color);
void	clear_textures(t_data *data);
int		check_textures_is_init(t_data *data, int status);

// ========== Errors ==========
void	free_mlx(t_data *data);
void	free_window(t_data *data);

#endif
