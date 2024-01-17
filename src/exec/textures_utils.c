/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:49:05 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/25 14:14:06 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_textures_is_init(t_data *data, int status)
{
	if (!data->north.img || !data->south.img || \
		!data->west.img || !data->east.img || status == FAILURE)
	{
		print_exec_err(E_TEXTURES, "check_textures_is_init");
		close_window(data, FAILURE);
		return (FAILURE);
	}
	return (SUCCESS);
}

void	clear_textures(t_data *data)
{
	if (data->north.img)
	{
		mlx_destroy_image(data->mlx_ptr, data->north.img);
		data->north.img = NULL;
	}
	if (data->south.img)
	{
		mlx_destroy_image(data->mlx_ptr, data->south.img);
		data->south.img = NULL;
	}
	if (data->west.img)
	{
		mlx_destroy_image(data->mlx_ptr, data->west.img);
		data->west.img = NULL;
	}
	if (data->east.img)
	{
		mlx_destroy_image(data->mlx_ptr, data->east.img);
		data->east.img = NULL;
	}
}
