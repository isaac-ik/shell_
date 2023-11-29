#include <stdio.h>
#include <stddef.h>
#include <string.h>

/**
 * main - main function
 * Programmer: Isaac-ik
 * @argc: argumnet count
 * @argv: argument vector
 * Return: nothing
 */
int splitStr(char *str)
{
	char *sep = " ";
	
	while (str != NULL)
	{
		str = strtok(str, sep);
		printf("%s\n", str);
	}
	return (0);
}
/**
 * main - main function
 * Programmer: Isaac-ik
 * @argc: argumnet count
 * @argv: argument vector
 * Return: nothing
 */
void main(int argc, char **argv)
{
	int i = 1;

	/* parse the argument vector */
	while (argv[i] != NULL)
	{
		printf("the argument number%i is %s\n", i, argv[i]);
		splitStr(argv[i]);
		i++;
	}
}
