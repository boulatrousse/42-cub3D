/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:16:24 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/30 17:59:24 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		get_textures(t_data *data, t_ray *ray, \
					t_vector_int pos, int tex_y);
static void		draw_floor(t_data *data, int width, int i);
static float	get_fisheye_distance(t_data *data, float length, float angle);

void	draw_walls(t_data *data, t_ray *ray, int width, float angle)
{
	int				i;
	int				tex_y;
	t_vector_int	pos;
	float			wall_height;

	(void)angle;
	i = 0;
	tex_y = 0;
	if (ray->length < MIN_LEN_RAY)
		ray->length = MIN_LEN_RAY;
	ray->length = get_fisheye_distance(data, ray->length, angle);
	wall_height = WALL_H / ray->length;
	while (i < (HEIGHT / 2) - (wall_height / 2))
	{
		put_pixel(&data->minimap, width, i, data->ceiling);
		i++;
	}
	while (i < (HEIGHT / 2) + (wall_height / 2))
	{
		pos.x = i;
		pos.y = width;
		get_textures(data, ray, pos, tex_y++);
		i++;
	}
	draw_floor(data, width, i);
}

static void	get_textures(t_data *data, t_ray *ray, t_vector_int pos, int tex_y)
{
	char	*dst;

	dst = draw_textures(data, ray, tex_y);
	if (!dst)
	{
		print_exec_err(E_PIXEL, "get_textures");
		close_window(data, FAILURE);
	}
	put_pixel(&data->minimap, pos.y, pos.x, *(unsigned int *)dst);
}

static void	draw_floor(t_data *data, int width, int i)
{
	while (i < HEIGHT)
	{
		put_pixel(&data->minimap, width, i, data->floor);
		i++;
	}
}

static float	get_fisheye_distance(t_data *data, float length, float angle)
{
	float	fish_eye_angle;

	fish_eye_angle = angle - data->player_pos.angle;
	length = length * cos(fish_eye_angle);
	return (length);
}
