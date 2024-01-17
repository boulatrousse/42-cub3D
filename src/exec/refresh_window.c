/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:05:16 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/30 13:20:15 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	error_refresh_window(t_data *data, int status);

int	refresh_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->minimap.img);
	data->minimap.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->minimap.img)
	{
		print_exec_err(E_IMG, "refresh_window");
		error_refresh_window(data, IMG_ERR);
	}
	data->minimap.addr = mlx_get_data_addr(data->minimap.img, \
			&data->minimap.bits_per_pixel, &data->minimap.line_length, \
				&data->minimap.endian);
	if (!data->minimap.addr)
	{
		print_exec_err(E_ADDR, "refresh_window");
		error_refresh_window(data, 0);
	}
	raycasting(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window, \
			data->minimap.img, 0, 0);
	return (SUCCESS);
}

static void	error_refresh_window(t_data *data, int status)
{
	clear_textures(data);
	mlx_clear_window(data->mlx_ptr, data->window);
	mlx_destroy_window(data->mlx_ptr, data->window);
	if (status != IMG_ERR)
		mlx_destroy_image(data->mlx_ptr, data->minimap.img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_data(data);
	exit(FAILURE);
}
