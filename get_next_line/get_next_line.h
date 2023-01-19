/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinaz <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:26:26 by kinaz             #+#    #+#             */
/*   Updated: 2022/12/05 17:58:26 by kinaz            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen1(const char *str);
char	*ft_strjoin1(char *str, char *buff);
char	*ft_strchr(const char *str, int c);
char	*ft_line(char *str);
char	*ft_str(char *str);
char	*ft_read_buff(int fd, char *str);
char	*get_next_line(int fd);

#endif
