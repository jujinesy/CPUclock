#include <windows.h>
#include <stdio.h>

int main()
{
	int i;
	//for (i = 0; i < 9999; i++)
	//{
	//	printf("%d\n", i);
	//	Sleep(1000);
	//}
	int start = 0, end = 0, time_data = 0;

	while (1)
	{
		i = 370000000;
		start = GetTickCount();
		
		while (i--)
		{
			_asm
			{
				xor eax, 1
			}
		}

		end = GetTickCount();
		time_data = end - start;
		printf("%d\n", time_data);
	}
	
	return 0;
}