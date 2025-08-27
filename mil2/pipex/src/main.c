#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> // PID_t
#include "libft.h"


/*
cc src/main.c -Iinclude/libft -Linclude/libft -lft
valgrind --leak-check=full --trace-children=yes ./a.out
*/
char	*get_path(char *cmd, char **env)
{
	size_t	i;
	char	**split_paths;
	char	*pathplus;
	char	*path;
	int		n_paths;

	i = 0;
	while (env[i] && !ft_strnstr(env[i], "PATH=", 5) && env[i][0] != 'P')
		i++;
	if (env[i] == NULL)
		perror("No PATH environmental variable found");
	split_paths = ft_split(env[i] + 5, ':');
	n_paths = ft_strwords(env[i], ':');
	i = -1;
	while (split_paths[++i])
	{
		pathplus = ft_strjoin(split_paths[i], "/");
		path = ft_strjoin(pathplus, cmd);
		free(pathplus);
		if (!access(path, X_OK))
			return (path);
		free(path);
	}
	ft_freesplit(split_paths, n_paths);
	return (perror("No command found"), NULL);
}

void	exec(char *cmd, char **env)
{
	char	*path;
	char	**split_cmd;

	split_cmd = ft_split(cmd, ' ');
	path = get_path(split_cmd[0], env);
	execve(path, split_cmd, env);
	ft_freesplit(split_cmd, ft_strwords(cmd, ' '));
	free(path);
}

int	main(int ac, char **av, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("No fork");
	else if (pid == 0)
		exec("cat file2", env);
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
		printf("HOla, hijo");
	}
	return (0);
}
