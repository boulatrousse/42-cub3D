/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:53:26 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/26 10:35:30 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_mlx_data *mlx_data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	dst = mlx_data->addr + (y * mlx_data->line_length + x * \
			(mlx_data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}
