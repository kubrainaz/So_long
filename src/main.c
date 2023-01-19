/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinaz <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:19:25 by kinaz             #+#    #+#             */
/*   Updated: 2022/12/05 17:19:28 by kinaz            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_image(t_data *data)
{
	if (!data->player_f)
		ft_error_file ("Error: Image not found\n", data);
	if (!data->player_b)
		ft_error_file ("Error: Image not found\n", data);
	if (!data->player_l)
		ft_error_file("Error: Image not found\n", data);
	if (!data->player_r)
		ft_error_file("Error: Image not found\n", data);
	if (!data->food)
		ft_error_file("Error: Image not found\n", data);
	if (!data->exit)
		ft_error_file("Error: Image not found\n", data);
	if (!data->background)
		ft_error_file("Error: Image not found\n", data);
	if (!data->wall)
		ft_error_file("Error: Image not found\n", data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		data = ft_calloc(sizeof(t_data), 1);
		ft_ber_check(av[1], data);
		ft_make_map(data, av[1]);
		ft_rectangular_check(data);
		ft_map_check(data);
		ft_wall_check(data);
		ft_validmap_check(data, data->ply_x, data->ply_y);
		ft_path_check(data);
		data->mlx = mlx_init();
		ft_init_image(data);
		ft_check_image(data);
		mlx_hook(data->window, 2, 1L << 0, ft_key_event, data);
		mlx_hook(data->window, 17, 1L << 2, ft_close_window, data);
		mlx_loop(data->mlx);
	}
	else
	{
		data = ft_calloc(sizeof(t_data), 1);
		ft_error("You just have to enter the map path!", data);
	}
}
