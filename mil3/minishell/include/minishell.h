/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:46:16 by xwu               #+#    #+#             */
/*   Updated: 2025/11/03 21:54:50 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_cmds
{
	char	*cmd;
	char	**options; //hay veces que son más de una letra
	char	*args; // problema: hay a veces que las opciones afectan al siguiente argumento solo
}			t_cmds;


typedef struct s_cmdtab
{
	int		infile;
	int		outfile;
	int		errfile;
	t_cmds	*cmds;
}			t_cmdtab;



#endif /* MINISHELL_H */