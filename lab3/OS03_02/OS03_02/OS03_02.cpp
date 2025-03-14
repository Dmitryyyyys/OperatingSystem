#include <iostream>
#include <windows.h>
#include <process.h>
using namespace std;

HANDLE runChildProcess(const wchar_t* programName) {
    setlocale(LC_ALL, "RUS");

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    
    if (!CreateProcess(
        programName,
        NULL,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi)) {
        cerr << "Создание процесса не удалось: " << GetLastError() << endl;
        return NULL;     }

    CloseHandle(pi.hThread); 
    return pi.hProcess; 
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Основной процесс ID: " << GetCurrentProcessId() << endl;

    
    HANDLE hChildProcess1 = runChildProcess(L"C:/labs/ОС/OS03_02/x64/Debug/OS03_02_1.exe");
    HANDLE hChildProcess2 = runChildProcess(L"C:/labs/ОС/OS03_02/x64/Debug/OS03_02_2.exe");

    for (int i = 0; i < 100; ++i) {
        cout << "Основной процесс итерация: " << i + 1 << " ID: " << GetCurrentProcessId() << endl;
        Sleep(1000);
    }

    
    if (hChildProcess1 != NULL) {
        WaitForSingleObject(hChildProcess1, INFINITE);
        CloseHandle(hChildProcess1); 
    }

    if (hChildProcess2 != NULL) {
        WaitForSingleObject(hChildProcess2, INFINITE);
        CloseHandle(hChildProcess2); 
    }

    return 0;
}
