/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 00:34:09 by xwu               #+#    #+#             */
/*   Updated: 2025/06/21 00:34:09 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);

char	*ft_pos_nl(const char *s);

size_t	ft_strlen(char *str);

void	ft_gnl_memmove(char *dest, const char *src, size_t count);

size_t	ft_strpdump(char **line, char *buffer, char *pos_nl);

#endif
