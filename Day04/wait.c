/*
좀비 프로세스를 종료 시키는 wait 함수
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int status;
	pid_t pid=fork();
	
	if(pid==0)
	{
		return 3;   	
	}
	else
	{
		printf("Child PID: %d \n", pid);
		pid=fork();
		if(pid==0)
		{
			exit(7);
		}
		else // 전부 부모
		{
			printf("Child PID: %d \n", pid);
			wait(&status); // 상태를 받음
			if(WIFEXITED(status)) // 자식프로세스가 정상적으로 반환시 true
				printf("Child send one: %d \n", WEXITSTATUS(status));

			wait(&status); 
			if(WIFEXITED(status))
				printf("Child send two: %d \n", WEXITSTATUS(status));
			sleep(30);     // Sleep 30 sec.
		}
	}
	return 0;
}
