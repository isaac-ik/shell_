#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	char *cmdBuff;
	size_t n = 10;
	int v;
	pid_t pid;
	ssize_t e;
	char **args = {NULL}, **envp = {NULL};

	cmdBuff = (char *)malloc((sizeof(char)) * n);
	if (cmdBuff == NULL)
	{
		return (-1);
	}
	printf("$ ");

	/* read every line written from stdin within the file */
	e = getline(&cmdBuff, &n, stdin);
	if (e == -1)
	{
		printf("command is %s\n", cmdBuff);
		printf("Error is in getline\n ");
		free(cmdBuff);
		return (-1);
	}

	/* create a child */
	pid = fork();
	if (pid == 0)
	{
		/* running the child process */
		v = execve(cmdBuff, args, envp);
		if (v == -1)
		{
			printf("command is %s\n", cmdBuff);
			printf("Error is in execve\n");
			free(cmdBuff);
			return (-1);
		}
	}
	if (pid == -1)
	{
		printf("command is %s\n", cmdBuff);
		printf("Error is fork\n");
		perror("ERROR");
		return (-2);
	}
	if (pid > 0)
	{
		/*running the parent process */
		wait(NULL);
	}
	printf("command is %s\n", cmdBuff);
	printf("No Error\n");
	free(cmdBuff);

	return (0);

}
