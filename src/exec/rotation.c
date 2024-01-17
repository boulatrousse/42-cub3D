/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:49:49 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/24 15:32:18 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	left_rotation(t_data *data);
static void	right_rotation(t_data *data);

void	rotation(t_data *data, int key)
{
	if (key == LEFT_ARROW)
		left_rotation(data);
	else if (key == RIGHT_ARROW)
		right_rotation(data);
	data->player_pos.dx = cos(data->player_pos.angle);
	data->player_pos.dy = sin(data->player_pos.angle);
}

static void	left_rotation(t_data *data)
{
	data->player_pos.angle += 0.1;
	if (data->player_pos.angle <= 0)
		data->player_pos.angle += 2 * PI;
}

static void	right_rotation(t_data *data)
{
	data->player_pos.angle -= 0.1;
	if (data->player_pos.angle > 2 * PI)
		data->player_pos.angle -= 2 * PI;
}
