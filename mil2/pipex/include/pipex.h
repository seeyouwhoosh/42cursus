/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:30:41 by xwu               #+#    #+#             */
/*   Updated: 2025/08/31 21:48:49 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

/* Get environmental variable PATH from the third argument of the main,
char **env */
char	*get_path(char *cmd, char **env);

/* Execute program */
void	exec(char *cmd, char **env);

/* Gets stream from stdin until limiter is inserted (following a newspace)*/
void	here_doc(char *limiter);

/* Util for here_doc */
void	here_doc_put(char *limiter, int fd);

/* A bit crappy version of the original get_next_line. Good thing is that the
memory allocation is dynamic */
char	*get_next_line(int fd);

/* Util for get_next_line */
void	get_line(int fd, char **line, size_t size);

#endif /* PIPEX_H */