#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	LPCWSTR an = L"C:/Windows/System32/notepad.exe";
		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		ZeroMemory(&si, sizeof(STARTUPINFO)); si.cb = sizeof(STARTUPINFO);
		if (
			CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)
			)
		{
			cout << "-- Process OS03_01 created\n";
			cout << "PROCESS ID: " << pi.dwProcessId << "\n";
		}
		else
			cout << "-- Process OS03_01  not created\n";
		for (int i = 0; i < 50; i++)
	{	Sleep(1000);
		cout << "OS03_01x: " << i << "\n";
	}
		WaitForSingleObject(pi.hProcess, INFINITE);
		CloseHandle(pi.hProcess);
		
		return 0;
}