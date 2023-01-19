/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinaz <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:19:43 by kinaz             #+#    #+#             */
/*   Updated: 2022/12/05 17:19:45 by kinaz            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_background(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window,
		data->background, x * 64, y * 64);
}

void	ft_wall(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window,
		data->wall, x * 64, y * 64);
}

void	ft_exit(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window,
		data->exit, x * 64, y * 64);
}

void	ft_food(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window,
		data->food, x * 64, y * 64);
}
