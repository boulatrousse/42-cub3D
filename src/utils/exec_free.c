/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:37:19 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/24 14:30:35 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mlx(t_data *data)
{
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

void	free_window(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->window);
	mlx_destroy_window(data->mlx_ptr, data->window);
}

void	close_fds(void)
{
	int		i;

	i = 0;
	while (i <= 1023)
	{
		close(i);
		i++;
	}
}
