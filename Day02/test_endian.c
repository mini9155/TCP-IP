#include <stdio.h>
#include <arpa/inet.h>

int main()
{
	int data = 0x12345678;
	char* ptr = (char*)&data; 
	 // 데이터 타입 int, char 형식으로 바꿔줘야 함

	for(int i = 0; i < sizeof(int); i++) {
		printf("%d, %#x\n", &ptr[i] , ptr[i]);
	}
}
