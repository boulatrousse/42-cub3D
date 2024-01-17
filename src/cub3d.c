/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:57:54 by croy              #+#    #+#             */
/*   Updated: 2023/10/24 11:07:48 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	int			exit_code;
	t_data		data;

	exit_code = EXIT_SUCCESS;
	if (ac != 2)
		return (print_perr(E_MISSING, NULL), EXIT_FAILURE);
	if (map_parsing(&data, av[1]))
		exit_code = EXIT_FAILURE;
	if (!exit_code && exec_manager(&data) != SUCCESS)
		exit_code = EXIT_FAILURE;
	free_data(&data);
	return (exit_code);
}
