#include <Windows.h>
#include <iostream>
using namespace std;
int main()
{
	DWORD pid = GetCurrentProcessId();
	DWORD tid = GetCurrentThreadId();

	unsigned long long d = MAXULONGLONG / 10000000000;
		for (unsigned long long i = 0; i < MAXULONGLONG; i++)
		{
			if (i % d == 0) cout << "PID = " << pid << ", TID = " << tid << " : " << i << "\n";
		}
		system("pause");
		return 0;

}