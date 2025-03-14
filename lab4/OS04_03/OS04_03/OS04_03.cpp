#include <Windows.h>
#include <iostream>
using namespace std;
DWORD WINAPI threadProc(LPVOID);

int main() {
	HANDLE hThread;
	DWORD dwThreadId;
	for (int Count = 0; Count < 1000000; Count++)
	{
		hThread = CreateThread(
			NULL, 0, threadProc, NULL, CREATE_SUSPENDED, &dwThreadId);
		if (hThread == INVALID_HANDLE_VALUE || hThread == NULL)
		{
			cout << ("CreateThread failed (error %d) after %d threads\n",
				GetLastError(), Count);
				
	}
		ResumeThread(hThread);
		CloseHandle(hThread);
		if (Count % 1000 == 0)
			cout << ("%d\n", Count);
	}
	cout << "Thread main exited\n";
	return 0;
}

DWORD WINAPI threadProc(LPVOID args)
{
	Sleep(600000);
	return 0;
}