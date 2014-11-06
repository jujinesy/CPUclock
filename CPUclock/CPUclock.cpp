#include "CPUclock.h"


CPUclock::CPUclock()
{
}


CPUclock::~CPUclock()
{
}

VOID CPUclock::ReadTSC(DWORD *dwLo, DWORD *dwHi)
{
	_asm
	{
		_emit    0x0F
		_emit    0x31

		mov      ecx, dword ptr dwLo
		mov      dword ptr[ecx], eax
		mov      ecx, dword ptr dwHi
		mov      dword ptr[ecx], edx
	}
}

ULONGLONG CPUclock::ClockRatePerfCt(unsigned long lnSamplePeriod)
{
	LARGE_INTEGER PerfCt, OldPerfCt, PerfFreq;
	ULARGE_INTEGER Cycle, OldCycle, ClockHz;


	QueryPerformanceFrequency(&PerfFreq);
	QueryPerformanceCounter(&OldPerfCt);
	ReadTSC(&OldCycle.u.LowPart, &OldCycle.u.HighPart);

	Sleep(lnSamplePeriod);

	QueryPerformanceCounter(&PerfCt);
	ReadTSC(&Cycle.u.LowPart, &Cycle.u.HighPart);

	ClockHz.QuadPart = (ULONGLONG)(Cycle.QuadPart - OldCycle.QuadPart);
	ClockHz.QuadPart = (ULONGLONG)(ClockHz.QuadPart * PerfFreq.QuadPart) / (PerfCt.QuadPart - OldPerfCt.QuadPart);

	return ClockHz.QuadPart;
}





int main()
{
	CPUclock cl;
	printf("Clock = %I64d", cl.ClockRatePerfCt(WAIT_PERIOD_MS));
	return 0;
}


