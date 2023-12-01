#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char **argv)
{
	char **envp = { NULL };
	char **args = {NULL};
	int i;
	pid_t pid;

	if (argc < 2)
	{
		perror("Useage: ./program <program>");
		return (-1);
	}


	for (i = 0; i < 5; i++)
	{
		/* create a child process */
		pid = fork();
		/* replace with a new one */
		if (pid == -1)
		{
			perror("Error occurred in creating the child");
			return (-2);
		}
		if (pid == 0)
		{
			execve(argv[1], args, envp);
		}
		if (pid > 0)
		{
			wait(NULL);
		}
	}
	return (0);
}

