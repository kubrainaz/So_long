/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinaz <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:26:26 by kinaz             #+#    #+#             */
/*   Updated: 2022/12/05 17:55:22 by kinaz            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	hay;
	size_t	need;

	hay = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[hay] != 0 && hay < n)
	{
		need = 0;
		while (haystack[hay + need] == needle[need]
			&& needle[need] && need + hay < n)
			need++;
		if (need == ft_strlen(needle))
			return ((char *)&haystack[hay]);
		hay++;
	}
	return (NULL);
}
