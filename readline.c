#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - main function
 * Programmer: Isaac-ik
 * @argc: argumnet count
 * @argv: argument vector
 * Return: nothing
 */
int main(int argc, char **argv)
{
	int i;
	ssize_t nd;
	size_t size;
	char *buff;

	size = 10;

	buff = (char *)malloc(sizeof(char) * size);
	if (buff == NULL)
		return (-1);

	printf("$ "); /* prompt */
	nd = getline(&buff, &size, stdin);
	if (nd == -1)
	{
		free(buff);
		return (-1);
	}
	printf("%s\nThe buffer size is %li\n", buff, size);
	return (0);
}
