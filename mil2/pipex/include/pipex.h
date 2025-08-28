/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:30:41 by xwu               #+#    #+#             */
/*   Updated: 2025/08/28 22:39:18 by xwu              ###   ########.fr       */
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

/* Child process */
void	child_process(char **av, char **env, int *pipe);

/* Parent process */
void	parent_process(char **av, char **env, int *pipe);

#endif /* PIPEX_H */