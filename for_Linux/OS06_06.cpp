#include <iostream>
#include <windows.h>

using namespace std;

HANDLE mutex;
int iteration = 1;

DWORD WINAPI threadFunction(LPVOID param)
{
    char* threadName = (char*)param;
    for (int i = 1; i <= 90; ++i)
    {
        if (i >= 30 && i <= 60)
        {
            WaitForSingleObject(mutex, INFINITE);  // Ожидаем мьютекс для синхронизации
        }

        // Выводим информацию о потоке и итерации
        printf("Thread [%s] - iteration %d\n", threadName, i);

        if (i >= 30 && i <= 60)
        {
            ReleaseMutex(mutex);  // Освобождаем мьютекс
        }

        Sleep(100);  // Задержка 0.1 сек
    }

    return 0;
}

int main()
{
    // Создаем мьютекс
    mutex = CreateMutex(NULL, FALSE, NULL);

    if (mutex == NULL)
    {
        cerr << "Error creating mutex" << endl;
        return 1;
    }

    // Создаем два потока A и B
    HANDLE threads[2];
    threads[0] = CreateThread(NULL, 0, threadFunction, (LPVOID)"A", 0, NULL);
    threads[1] = CreateThread(NULL, 0, threadFunction, (LPVOID)"B", 0, NULL);

    // Основной поток также выполняет цикл
    for (int i = 1; i <= 90; ++i)
    {
        if (i >= 30 && i <= 60)
        {
            WaitForSingleObject(mutex, INFINITE);  // Ожидаем мьютекс
        }

        // Выводим информацию о потоке main и итерации
        printf("Thread [main] - iteration %d\n", i);

        if (i >= 30 && i <= 60)
        {
            ReleaseMutex(mutex);  // Освобождаем мьютекс
        }

        Sleep(100);  // Задержка 0.1 сек
    }

    // Ожидаем завершения потоков A и B
    WaitForMultipleObjects(2, threads, TRUE, INFINITE);

    // Закрываем мьютекс и дескрипторы потоков
    CloseHandle(threads[0]);
    CloseHandle(threads[1]);
    CloseHandle(mutex);

    return 0;
}
