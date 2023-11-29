#include <stdio.h>
#include <stddef.h>

/**
 * main - main function
 * Programmer: Isaac-ik
 * @argc: argumnet count
 * @argv: argument vector
 * Return: nothing
 */
void main(int argc, char **argv)
{
	int i;

	/* parse the argument vector */
	while (argv[i] != NULL)
	{
		printf("the argument number%i is %s\n", i, argv[i]);
		i++;
	}
}
