/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:37:26 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/25 14:07:54 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exec_manager(t_data *data)
{
	if (init_mlx(data) != SUCCESS)
		return (FAILURE);
	if (init_textures(data) != SUCCESS)
		return (FAILURE);
	mlx_loop_hook(data->mlx_ptr, refresh_window, data);
	mlx_hook(data->window, 2, 1L << 0, moves, data);
	mlx_hook(data->window, 17, 1L << 17, close_window, data);
	mlx_loop(data->mlx_ptr);
	return (SUCCESS);
}
