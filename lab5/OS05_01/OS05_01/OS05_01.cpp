#include <iostream>
#include <windows.h>
#include <bitset>

int main() {
    // Получение идентификатора текущего процесса
    DWORD processId = GetCurrentProcessId();
    std::cout << "Process ID: " << processId << std::endl;

    // Получение идентификатора текущего потока (main thread)
    DWORD threadId = GetCurrentThreadId();
    std::cout << "Thread ID: " << threadId << std::endl;

    // Получение приоритетного класса процесса
    HANDLE hProcess = GetCurrentProcess();
    DWORD processPriorityClass = GetPriorityClass(hProcess);
    std::cout << "Process Priority Class: " << processPriorityClass << std::endl;

    // Получение приоритета текущего потока
    HANDLE hThread = GetCurrentThread();
    int threadPriority = GetThreadPriority(hThread);
    std::cout << "Thread Priority: " << threadPriority << std::endl;

    // Получение маски доступных процессору процессоров (affinity mask)
    DWORD_PTR processAffinityMask, systemAffinityMask;
    if (GetProcessAffinityMask(hProcess, &processAffinityMask, &systemAffinityMask)) {
        std::cout << "Process Affinity Mask (binary): " << std::bitset<64>(processAffinityMask) << std::endl;
    }
    else {
        std::cerr << "Failed to get affinity mask" << std::endl;
    }

    // Количество доступных процессоров
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    std::cout << "Number of Processors: " << sysInfo.dwNumberOfProcessors << std::endl;

    // Получение номера процессора, на котором выполняется текущий поток
    DWORD processorNumber = GetCurrentProcessorNumber();
    std::cout << "Current Processor: " << processorNumber << std::endl;

    return 0;
}
