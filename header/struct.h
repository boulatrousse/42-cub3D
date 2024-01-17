/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:59:44 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/26 08:23:24 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

// ========== Vectors ==========
typedef struct s_vector_int
{
	int				x;
	int				y;
}				t_vector_int;

typedef struct s_vector_float
{
	float			x;
	float			y;
}				t_vector_float;

typedef struct s_player
{
	float				x;
	float				y;
	float				dx;
	float				dy;
	float				angle;
}				t_player;

typedef enum s_cardinal_pts
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}				t_cardinal_pts;

typedef struct s_draw
{
	int				start;
	int				end;
	int				height;
}				t_draw;

typedef struct s_ray
{
	t_vector_float		delta;
	t_vector_float		dist_to_wall;

	t_vector_int		step;
	t_vector_int		map_pos;

	t_cardinal_pts		cardinal;

	float				length;
	float				collision;
}				t_ray;

typedef struct s_mlx_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_mlx_data;

typedef struct s_texture
{
	int		fd;
	char	*path;
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_map
{
	char	**array;
	size_t	width;
	size_t	height;
}	t_map;

typedef struct s_data
{
	char			*file;
	char			**split_file;
	t_texture		north;
	t_texture		south;
	t_texture		west;
	t_texture		east;
	unsigned int	floor;
	unsigned int	ceiling;
	t_map			*map;
	char			nswe;
	void			*mlx_ptr;
	void			*window;
	t_mlx_data		minimap;
	t_player		player_pos;

	int				pix;
}	t_data;

#endif
