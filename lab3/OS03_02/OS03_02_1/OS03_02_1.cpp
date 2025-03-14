#include <iostream>
#include <windows.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");

	cout << "Процесс OS03_02_1 ID: " << GetCurrentProcessId() << endl;
	for (int i = 0; i < 50; ++i)
	{
		cout << "OS03_02_1 итерация: " << i + 1 << " ID: " << GetCurrentProcessId() << endl;
		Sleep(1000);
	}
	return 0;
}
