#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * infinite_while - check the code
 * Return: zero but it will not get to that
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}


/**
 * main - check the code
 * Return: Nothing
 */
int main(void)
{
	int	pid;
	int i = 0;

	pid = fork();
	while (i++ < 4)
		if (pid)
			pid = fork();
	if (!pid)
	{
		printf("Zombie process created, PID: %d\n", getpid());
		infinite_while();
	}
	exit(0);
	return (0);
}
