#include <windows.h>
#include <winbase.h>
#include <intrin.h>

//uint64_t rdtsc(){
LONGLONG rdtsc(){
	return __rdtsc();
}

void main()
{
	// 시작, 끝, 주기 진동수를 얻을 구조체를 선언한다.
	LARGE_INTEGER start, end, f,first,second;
	CPUclock cl;
	
	while (1)
	{
		getchar();
		// 고해상도 타이머의 주기를 얻는다.
		QueryPerformanceFrequency(&f);

		// 시작 시점의 진동수를 얻는다.
		printf("%I64d\n", first.QuadPart = __rdtsc());
		QueryPerformanceCounter(&start);

		// 프로세스를 0.001초간 중지시킨다.
		//Sleep(1000);
		
		for (int i = 0; i < 100000; i++)
		{
			//
			_asm
			{
				push eax
				pop eax
				push eax
				pop eax
				push eax
				pop eax
				push eax
				pop eax
				push eax
				pop eax
				push eax
				pop eax
			}
			//
		}
		

		// 끝 시점의 진동수를 얻는다.
		QueryPerformanceCounter(&end);
		printf("%I64d\n", second.QuadPart = __rdtsc());
		printf("%I64d\n", second.QuadPart - first.QuadPart);

		// 끝 시점의 진동수에서 시작 시점의 진동수를 뺀 후 진동수에서 1000으로 나눈 값을 나눈다.
		// 1초 기준의 주기를 1000 으로 나누었기 때문에 1밀리초 동안 발생하는 진동수로 나눈 셈이다.
		__int64 ms_interval = (end.QuadPart - start.QuadPart) / (f.QuadPart / 1000);

		// 끝 시점의 진동수에서 시작 시점의 진동수를 뺀 후 진동수에서 1000000으로 나눈 값을 나눈다.
		// 1초 기준의 주기를 1000000 으로 나누었기 때문에 1마이크로초 동안 발생하는 진동수로 나눈 셈이다.
		__int64 micro_interval = (end.QuadPart - start.QuadPart) / (f.QuadPart / 1000000);

		// 결과 값을 밀리초와 마이크로초로 출력한다.
		printf("millisecond : %d, microsecond : %d\n", (int)ms_interval, (int)micro_interval);
		printf("Clock = %I64d\n", cl.ClockRatePerfCt(WAIT_PERIOD_MS));
	}
	
}