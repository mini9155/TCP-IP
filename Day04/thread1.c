/*
스레드가 개별적으로 가지고 있는 메모리 영역
ㄴ 스택 영역

지역변수
함수가 호출되고 실행되면스택 영역을 할당 받음
함수 호출이 끝나면 스택 영역은 반환

전역변수
ㄴ 전역 변수는 프로그램 시작과 끝까지 존재함

스레드는 개별적으로 할당이 된다
데이터, 힙 영역은 공통적으로 사용
*/

#include <stdio.h>
#include <pthread.h>
void* thread_main(void *arg);

int main(int argc, char *argv[]) 
{
	pthread_t t_id;
	int thread_param=5;
	
	if(pthread_create(&t_id, NULL, thread_main, (void*)&thread_param)!=0)
	{
		puts("pthread_create() error");
		return -1;
	}; 	
	sleep(10);  puts("end of main");
	return 0;
}

void* thread_main(void *arg) 
{
	int i;
	int cnt=*((int*)arg);
	for(i=0; i<cnt; i++)
	{
		sleep(1);  puts("running thread");	 
	}
	return NULL;
}
