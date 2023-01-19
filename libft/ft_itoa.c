/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinaz <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:26:26 by kinaz             #+#    #+#             */
/*   Updated: 2022/12/05 17:29:41 by kinaz            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_len(long src)
{
	int	i;

	i = 0;
	if (src == 0)
		return (1);
	if (src < 0)
		i++;
	while (src)
	{
		src /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	num;

	num = n;
	i = ft_len(num);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	str[i] = 0;
	i--;
	while (i >= (n < 0))
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (str);
}
