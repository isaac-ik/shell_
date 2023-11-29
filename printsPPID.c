#include <unistd.h>
#include <stdio.h>

/**
 * printPPID - prints the PPID of a process
 * programmer: Isaac-ik
 * Return: nothing
 */
void main(void)
{
	printf("The PPID of this process is %i\nThe PID is %i\n", getppid(), getpid());

}
