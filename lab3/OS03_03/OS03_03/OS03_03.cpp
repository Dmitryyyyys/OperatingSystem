#include <iostream>
#include <windows.h>
#include <psapi.h>

using namespace std;

void listProcesses() {
    DWORD processIds[1024], processCount;

   
    if (!EnumProcesses(processIds, sizeof(processIds), &processCount)) {
        cerr << "Ошибка при получении процессов: " << GetLastError() << endl;
        return;
    }

    processCount /= sizeof(DWORD); 

   
    for (unsigned int i = 0; i < processCount; ++i) {
        DWORD processId = processIds[i];
        if (processId != 0) {
   
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processId);
            if (hProcess) {
                TCHAR processName[MAX_PATH];
                HMODULE hModule;
                DWORD cbNeeded;

                if (EnumProcessModules(hProcess, &hModule, sizeof(hModule), &cbNeeded)) {
                    if (GetModuleFileNameEx(hProcess, hModule, processName, sizeof(processName) / sizeof(TCHAR))) {
                        wcout << L"Процесс: " << processName << L" | PID: " << processId << endl;
                    }
                }
                CloseHandle(hProcess);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Список выполняющихся процессов:" << endl;
    listProcesses();

    return 0;
}
