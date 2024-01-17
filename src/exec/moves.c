/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:43:05 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/24 14:36:56 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_w(t_data *data);
static void	move_a(t_data *data);
static void	move_s(t_data *data);
static void	move_d(t_data *data);

int	moves(int key_code, t_data *data)
{
	if (key_code == KEY_ESC)
		close_window(data, SUCCESS);
	else if (key_code == KEY_W)
		move_w(data);
	else if (key_code == KEY_A)
		move_a(data);
	else if (key_code == KEY_S)
		move_s(data);
	else if (key_code == KEY_D)
		move_d(data);
	else if (key_code == LEFT_ARROW)
		rotation(data, key_code);
	else if (key_code == RIGHT_ARROW)
		rotation(data, key_code);
	return (SUCCESS);
}

static void	move_w(t_data *data)
{
	t_vector_float		tmp;

	tmp.x = data->player_pos.x;
	tmp.y = data->player_pos.y;
	tmp.x += data->player_pos.dx / (SIZE_WALL / 10);
	tmp.y += data->player_pos.dy / (SIZE_WALL / 10);
	if (data->map->array[(int)(tmp.x + TOL)][(int)(tmp.y + TOL)] == '1')
		return ;
	if (data->map->array[(int)(tmp.x - TOL)][(int)(tmp.y - TOL)] == '1')
		return ;
	data->player_pos.x += data->player_pos.dx / (SIZE_WALL / 10);
	data->player_pos.y += data->player_pos.dy / (SIZE_WALL / 10);
}

static void	move_s(t_data *data)
{
	t_vector_float		tmp;

	tmp.x = data->player_pos.x;
	tmp.y = data->player_pos.y;
	tmp.x -= data->player_pos.dx / (SIZE_WALL / 10);
	tmp.y -= data->player_pos.dy / (SIZE_WALL / 10);
	if (data->map->array[(int)(tmp.x + TOL)][(int)(tmp.y + TOL)] == '1')
		return ;
	if (data->map->array[(int)(tmp.x - TOL)][(int)(tmp.y - TOL)] == '1')
		return ;
	data->player_pos.x -= data->player_pos.dx / (SIZE_WALL / 10);
	data->player_pos.y -= data->player_pos.dy / (SIZE_WALL / 10);
}

static void	move_a(t_data *data)
{
	t_vector_float		tmp;

	tmp.x = data->player_pos.x;
	tmp.y = data->player_pos.y;
	tmp.x += (cos(data->player_pos.angle + (PI / 2)) / 10);
	tmp.y += (sin(data->player_pos.angle + (PI / 2)) / 10);
	if (data->map->array[(int)(tmp.x + TOL)][(int)(tmp.y + TOL)] == '1')
		return ;
	if (data->map->array[(int)(tmp.x - TOL)][(int)(tmp.y - TOL)] == '1')
		return ;
	data->player_pos.x += (cos(data->player_pos.angle + (PI / 2)) / 10);
	data->player_pos.y += (sin(data->player_pos.angle + (PI / 2)) / 10);
}

static void	move_d(t_data *data)
{
	t_vector_float		tmp;

	tmp.x = data->player_pos.x;
	tmp.y = data->player_pos.y;
	tmp.x -= (cos(data->player_pos.angle + (PI / 2)) / 10);
	tmp.y -= (sin(data->player_pos.angle + (PI / 2)) / 10);
	if (data->map->array[(int)(tmp.x + TOL)][(int)(tmp.y + TOL)] == '1')
		return ;
	if (data->map->array[(int)(tmp.x - TOL)][(int)(tmp.y - TOL)] == '1')
		return ;
	data->player_pos.x -= (cos(data->player_pos.angle + (PI / 2)) / 10);
	data->player_pos.y -= (sin(data->player_pos.angle + (PI / 2)) / 10);
}
