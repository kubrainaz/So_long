/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinaz <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:20:01 by kinaz             #+#    #+#             */
/*   Updated: 2022/12/05 17:20:04 by kinaz            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_make_map(t_data *data, char *map)
{
	int		fd;
	char	*buff;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("File don't found!", data);
	buff = get_next_line(fd);
	if (!buff)
		ft_error("File is empty!", data);
	while (buff)
	{
		data->map1 = ft_strjoin(data->map1, buff);
		free(buff);
		buff = get_next_line(fd);
	}
	free(buff);
	data->map2 = ft_split(data->map1, '\n');
	data->tmp_map2 = ft_split(data->map1, '\n');
}

void	ft_init_image(t_data *data)
{
	data->player_f = mlx_xpm_file_to_image(data->mlx, PL_FT,
			&data->imgx, &data->imgy);
	data->player_b = mlx_xpm_file_to_image(data->mlx, PL_BK,
			&data->imgx, &data->imgy);
	data->player_l = mlx_xpm_file_to_image(data->mlx, PL_LT,
			&data->imgx, &data->imgy);
	data->player_r = mlx_xpm_file_to_image(data->mlx, PL_RT,
			&data->imgx, &data->imgy);
	data->food = mlx_xpm_file_to_image(data->mlx, FOOD,
			&data->imgx, &data->imgy);
	data->exit = mlx_xpm_file_to_image(data->mlx, EXIT,
			&data->imgx, &data->imgy);
	data->background = mlx_xpm_file_to_image(data->mlx, BACKG,
			&data->imgx, &data->imgy);
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL,
			&data->imgx, &data->imgy);
	data->window = mlx_new_window(data->mlx, data->map_x * 64, \
		data->map_y * 64, "so_long");
	ft_check_image(data);
	data->curr_pos = 'F';
	ft_put_image(data);
}

void	ft_put_image(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_put_image_2(x, y, data);
	ft_score(data);
}

void	ft_put_image_2(int x, int y, t_data *data)
{
	while (y < data->map_y)
	{
		x = 0;
		while (x < data->map_x)
		{
			if (data->map2[y][x] != 1 && data->map2[y][x] != 0)
				ft_background(data, x, y);
			if (data->map2[y][x] == '1')
				ft_wall(data, x, y);
			else if (data->map2[y][x] == '0')
				ft_background(data, x, y);
			else if (data->map2[y][x] == 'E')
				ft_exit(data, x, y);
			else if (data->map2[y][x] == 'C')
				ft_food(data, x, y);
			else if (data->map2[y][x] == 'P')
				ft_put_image_player(data, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	ft_put_image_player(t_data *data, int x, int y)
{
	if (data->curr_pos == 'F')
		mlx_put_image_to_window(data->mlx, data->window, data->player_f, x, y);
	else if (data->curr_pos == 'R')
		mlx_put_image_to_window(data->mlx, data->window, data->player_r, x, y);
	else if (data->curr_pos == 'L')
		mlx_put_image_to_window(data->mlx, data->window, data->player_l, x, y);
	else if (data->curr_pos == 'B')
		mlx_put_image_to_window(data->mlx, data->window, data->player_b, x, y);
}
