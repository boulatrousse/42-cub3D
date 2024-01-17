/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:51:24 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/25 16:19:32 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_ray_step_x(t_data *data, t_ray *ray, float dir_x);
static void	get_ray_step_y(t_data *data, t_ray *ray, float dir_y);

void	init_ray_struct(t_data *data, t_ray *ray, float dir_x, float dir_y)
{
	ray->delta.x = fabs(1.0f / dir_x);
	ray->delta.y = fabs(1.0f / dir_y);
	get_ray_step_x(data, ray, dir_x);
	get_ray_step_y(data, ray, dir_y);
	ray->map_pos.x = (int)data->player_pos.x;
	ray->map_pos.y = (int)data->player_pos.y;
	ray->length = 0.0f;
}

static void	get_ray_step_x(t_data *data, t_ray *ray, float dir_x)
{
	float		player_pos;

	player_pos = data->player_pos.x;
	if (dir_x < 0)
	{
		ray->step.x = -1;
		ray->cardinal = WEST;
		ray->dist_to_wall.x = (player_pos - (int)player_pos) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->cardinal = EAST;
		ray->dist_to_wall.x = ((int)player_pos + 1.0f - player_pos) \
			* ray->delta.x;
	}
}

static void	get_ray_step_y(t_data *data, t_ray *ray, float dir_y)
{
	float		player_pos;

	player_pos = data->player_pos.y;
	if (dir_y < 0)
	{
		ray->step.y = -1;
		ray->cardinal = SOUTH;
		ray->dist_to_wall.y = (player_pos - (int)player_pos) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->cardinal = NORTH;
		ray->dist_to_wall.y = ((int)player_pos + 1.0f - player_pos) \
			* ray->delta.y;
	}
}
