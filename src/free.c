/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinaz <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:18:02 by kinaz             #+#    #+#             */
/*   Updated: 2022/12/05 17:18:18 by kinaz            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *msg, t_data *data)
{
	ft_printf(msg);
	ft_free_all(data);
	exit(EXIT_FAILURE);
}

void	ft_error_file(char *msg, t_data *data)
{
	ft_printf(msg);
	exit(EXIT_FAILURE);
}

int	ft_close_window(t_data *data)
{
	ft_free_all(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_free_all(t_data *data)
{
	int	i;

	i = 0;
	if (data->map1)
		free(data->map1);
	if (data->map2)
	{
		while (data->map2[i])
		{
			free(data->map2[i]);
			i++;
		}
		free(data->map2);
	}
}
