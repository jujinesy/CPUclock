#include <windows.h>
#include <winbase.h>
#include <intrin.h>

//uint64_t rdtsc(){
LONGLONG rdtsc(){
	return __rdtsc();
}

void main()
{
	// ����, ��, �ֱ� �������� ���� ����ü�� �����Ѵ�.
	LARGE_INTEGER start, end, f,first,second;
	CPUclock cl;
	
	while (1)
	{
		getchar();
		// ���ػ� Ÿ�̸��� �ֱ⸦ ��´�.
		QueryPerformanceFrequency(&f);

		// ���� ������ �������� ��´�.
		printf("%I64d\n", first.QuadPart = __rdtsc());
		QueryPerformanceCounter(&start);

		// ���μ����� 0.001�ʰ� ������Ų��.
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
		

		// �� ������ �������� ��´�.
		QueryPerformanceCounter(&end);
		printf("%I64d\n", second.QuadPart = __rdtsc());
		printf("%I64d\n", second.QuadPart - first.QuadPart);

		// �� ������ ���������� ���� ������ �������� �� �� ���������� 1000���� ���� ���� ������.
		// 1�� ������ �ֱ⸦ 1000 ���� �������� ������ 1�и��� ���� �߻��ϴ� �������� ���� ���̴�.
		__int64 ms_interval = (end.QuadPart - start.QuadPart) / (f.QuadPart / 1000);

		// �� ������ ���������� ���� ������ �������� �� �� ���������� 1000000���� ���� ���� ������.
		// 1�� ������ �ֱ⸦ 1000000 ���� �������� ������ 1����ũ���� ���� �߻��ϴ� �������� ���� ���̴�.
		__int64 micro_interval = (end.QuadPart - start.QuadPart) / (f.QuadPart / 1000000);

		// ��� ���� �и��ʿ� ����ũ���ʷ� ����Ѵ�.
		printf("millisecond : %d, microsecond : %d\n", (int)ms_interval, (int)micro_interval);
		printf("Clock = %I64d\n", cl.ClockRatePerfCt(WAIT_PERIOD_MS));
	}
	
}