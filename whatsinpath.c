#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (int argc, char **argv)
{
	pid_t pid;
	char **envp = {NULL};
	char **argV = {NULL};
	int a;

	if (argc < 2 || argc > 2)
	{
		perror("Useage: _which filename\n");
		return (-1);
	}

	argV = (char **)malloc(sizeof(char *) * (argc - 1));

	argV[0] = argv[1];

	/* get the command line args */
	pid = fork();
	if (pid == -1)
	{
		free(argV);
		return (-1);
	}
	if (pid == 0)
	{
		a = execve("/bin/find", argV, envp);
		if (a == -1)
		{
			free(argV);
			return (-1);
		}
	}
	if (pid > 0)
	{
		wait(NULL);
	}

	free(argV);

	return (0);

}
