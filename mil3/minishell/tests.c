#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>

#define RED \e[1;31m
#define NONE \e[0;0m

int main(int ac, char **av, char **env)
{
	/* char *getenv(const char *name); */
	for (size_t i = 0; env[i]; i++)
		printf("%s\n", env[i]); // aquí se imprimen todas las environmental variables
	char *envs = getenv("PATH");
	printf("\e[0;31mGETENV: %s\n\e[0;0m", envs);

	/* char *getcwd(char *buf, size_t size);
	int chdir(const char *path); */
	char *cwd = malloc(100);
	char *changed = malloc(100);
	getcwd(cwd, 100);
	printf("\e[0;32mCURRENT WORKING DIRECTORY: %s\n\e[0;0m", cwd);
	if (chdir(".."))
		perror("chdir");
	getcwd(changed, 100);
	printf("\e[0;32mCURRENT WORKING DIRECTORY: %s\n\e[0;0m", changed);
	chdir(cwd);

	/* pid_t fork(void); */
	int	nb = 0;
	pid_t pid = fork();
	if (pid < 0)
		printf("\e[0;33mERROR: %d\n\e[0;0m", pid);
	if (!pid)
	{
		printf("\e[0;33mCHILD PROCESS: %d\n\e[0;0m", pid);
		printf("%d\n", ++nb);
		exit(0);
	}
	wait(NULL);
	printf("\e[0;33mPARENT PROCESS: %d\n\e[0;0m", pid);
	printf("%d\n", --nb);

	/* char *ttyname(int fildes);
	int ttyslot(void); */
	printf("\e[0;34mPATHNAME OF TERMINAL: %s\n\e[0;0m", ttyname(0));
	printf("\e[0;34mINDEX OF CURRENT TERMINAL: %d\n\e[0;0m", ttyslot());

	/* int unlink(const char *path); */
	if (system("touch think; echo 'think file created'; ls"))
		perror("touch command");
	if (unlink("think"))
		perror("unlink");

	signal(SIGINT, SIG_DFL)
	while (1)
		pause();
}


