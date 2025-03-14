#include <windows.h>
#include <iostream>
#include <thread>

using namespace std;

void OS04_02_T1() {
	DWORD pid = GetCurrentProcessId();
	DWORD tid = GetCurrentThreadId();
	for (int i = 0; i < 50; i++)
	{
		cout << "Thread T1 - PID: " << pid << ", TID: " << tid << " : " << i + 1 << endl;
		Sleep(1000);
	}
}

void OS04_02_T2() {
	DWORD pid = GetCurrentProcessId();
	DWORD tid = GetCurrentThreadId();
	for (int i = 0; i < 125; i++)
	{
		cout << "Thread T2 - PID: " << pid << ", TID: " << tid << " : " << i + 1 << endl;
		Sleep(1000);
	}
}
int main() {
	DWORD pid = GetCurrentProcessId();
	thread t1(OS04_02_T1);
	thread t2(OS04_02_T2);
	for (int i = 0; i < 100; i++)
	{
		cout << "Main process: - PID: " << pid << " : " << i + 1 << endl;
		Sleep(1000);
	}
	t1.join();
	t2.join();

	return 0;

}