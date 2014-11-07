#include <Windows.h>
#include <stdio.h>

void usleep(DWORD waitTime){
	LARGE_INTEGER perfCnt, start, now;

	QueryPerformanceFrequency(&perfCnt);
	QueryPerformanceCounter(&start);

	do {
		QueryPerformanceCounter((LARGE_INTEGER*)&now);
	} while ((now.QuadPart - start.QuadPart) / float(perfCnt.QuadPart) * 1000 * 1000 < waitTime);
	printf("now.QuadPart = %I64d\nstart.QuadPart = %I64d\nnow.QuadPart - start.QuadPart = %I64d\n", now.QuadPart, start.QuadPart, now.QuadPart - start.QuadPart);
}

int main(){
	int start = 0, end = 0, time_data = 0;

	while (1)
	{
		start = GetTickCount();

		usleep(1000000);

		end = GetTickCount();
		time_data = end - start;
		printf("%d\n", time_data);
	}
	
	return 0;
}


