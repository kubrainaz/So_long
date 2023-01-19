/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinaz <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:17:09 by kinaz             #+#    #+#             */
/*   Updated: 2022/12/05 17:17:12 by kinaz            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ber_check(char *map_name, t_data *data)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[len - 1] != 'r' || map_name[len - 2] != 'e'
		|| map_name[len - 3] != 'b' || map_name[len - 4] != '.')
		ft_error("Must be '.ber' extension!", data);
}

void	ft_map_check(t_data *data)
{
	static int	i = 0;
	static int	j = 0;

	while (data->map2[i])
	{
		j = 0;
		while (data->map2[i][j])
		{
			if (data->map2[i][j] == 'C')
				data->food_count++;
			else if (data->map2[i][j] == 'E')
				data->exit_count++;
			else if (data->map2[i][j] == 'P')
			{
				data->player_count++;
				data->ply_x = j;
				data->ply_y = i;
			}
			else if (data->map2[i][j] != '0' && data->map2[i][j] != '1')
				ft_error("Error! Map must include 1P or 1C or 1E.", data);
			j++;
		}
		i++;
	}
	ft_fe_count_check(data);
}

void	ft_rectangular_check(t_data *data)
{
	char		*tmp;
	static int	i = 0;

	tmp = data->map1;
	while (*tmp != '\n')
	{
		i++;
		tmp++;
	}
	data->map_x = i;
	tmp = data->map1 + data->map_x + 1;
	ft_rectangular_check_2(tmp, data);
}

void	ft_rectangular_check_2(char *tmp, t_data *data)
{
	int	i;

	i = 0;
	while (*tmp != '\0')
	{
		if (*tmp == '\n')
		{
			if (i != data->map_x)
				ft_error("Error! Rectangular error!", data);
			i = 0;
		}
		else
			i++;
		tmp++;
	}
	if (i != data->map_x)
		ft_error("Error2! Rectangular error!", data);
}
