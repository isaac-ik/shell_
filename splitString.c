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
	char *s;
	
	if (str == NULL)
	{
		return (-1);
	}

	s = strtok(str, sep);
	
	while (s != NULL)
	{
		printf("%s\n", s);
		s = strtok(NULL, sep);
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
	int i = 0;
	int result;

	/* parse the argument vector */
	while (argv[i] != NULL)
	{
		printf("the argument number %i is %s\n", i, argv[i]);
		result = splitStr(argv[i]);
		if (result == -1)
		{
			printf(" unable to split\n");
		}
		i++;
	}
}
