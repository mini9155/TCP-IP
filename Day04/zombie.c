/*
좀비프로세스
*/

#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	pid_t pid=fork();

	if(pid == 0) // if child process
	{
		puts("Hi I'm Child");
	}
	else
	{
		printf("Child Process ID : %d \n", pid);
		sleep(30);
	}

	if(pid ==0)
		puts("End Child Process");
	else
		puts("End Parent Process");
	return 0;
}

