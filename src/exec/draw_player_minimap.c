/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_minimap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:58:57 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/30 13:43:30 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player_minimap(t_mlx_data *minimap, float x, float y, int size_map)
{
	t_vector_float		p_position;
	float				cut;
	int					resize;

	cut = size_map / SIZE_CUT;
	resize = (SIZE_MAP - size_map) / 2;
	p_position.x = (x * size_map);
	p_position.y = (y * size_map);
	while ((p_position.x) < (x * size_map + resize) + cut)
	{
		p_position.y = y * size_map;
		while ((p_position.y) < (y * size_map + resize) + cut)
		{
			put_pixel(minimap, p_position.y, p_position.x, MAP_PLAYER);
			p_position.y++;
		}
		p_position.x++;
	}
}
