#pragma once
#include <windows.h>
#define WAIT_PERIOD_MS 1000
ULONGLONG ClockRatePerfCt(unsigned long lnSamplePeriod);
#include <iostream>
#include <limits.h>

class CPUclock
{
public:
	CPUclock();
	~CPUclock();
	VOID ReadTSC(DWORD *dwLo, DWORD *dwHi);
	ULONGLONG ClockRatePerfCt(unsigned long lnSamplePeriod);

};

