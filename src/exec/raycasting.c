/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:28:28 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/30 15:28:04 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_data *data)
{
	int					w;
	float				angle;
	t_ray				ray;
	t_vector_float		direction;

	w = WIDTH;
	angle = data->player_pos.angle - (20.0 * RAD);
	while (w >= 0)
	{
		direction.x = cos(angle);
		direction.y = sin(angle);
		init_ray_struct(data, &ray, direction.x, direction.y);
		ft_dda(data, &ray, direction);
		draw_walls(data, &ray, w, angle);
		angle += (RAD * (40.00 / (WIDTH)));
		w--;
	}
}
