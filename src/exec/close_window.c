/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:41:53 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/25 10:24:17 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_data *data, int status)
{
	clear_textures(data);
	mlx_clear_window(data->mlx_ptr, data->window);
	mlx_destroy_window(data->mlx_ptr, data->window);
	mlx_destroy_image(data->mlx_ptr, data->minimap.img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_data(data);
	if (status == SUCCESS)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
