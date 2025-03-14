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
            WaitForSingleObject(mutex, INFINITE);  // ������� ������� ��� �������������
        }

        // ������� ���������� � ������ � ��������
        printf("Thread [%s] - iteration %d\n", threadName, i);

        if (i >= 30 && i <= 60)
        {
            ReleaseMutex(mutex);  // ����������� �������
        }

        Sleep(100);  // �������� 0.1 ���
    }

    return 0;
}

int main()
{
    // ������� �������
    mutex = CreateMutex(NULL, FALSE, NULL);

    if (mutex == NULL)
    {
        cerr << "Error creating mutex" << endl;
        return 1;
    }

    // ������� ��� ������ A � B
    HANDLE threads[2];
    threads[0] = CreateThread(NULL, 0, threadFunction, (LPVOID)"A", 0, NULL);
    threads[1] = CreateThread(NULL, 0, threadFunction, (LPVOID)"B", 0, NULL);

    // �������� ����� ����� ��������� ����
    for (int i = 1; i <= 90; ++i)
    {
        if (i >= 30 && i <= 60)
        {
            WaitForSingleObject(mutex, INFINITE);  // ������� �������
        }

        // ������� ���������� � ������ main � ��������
        printf("Thread [main] - iteration %d\n", i);

        if (i >= 30 && i <= 60)
        {
            ReleaseMutex(mutex);  // ����������� �������
        }

        Sleep(100);  // �������� 0.1 ���
    }

    // ������� ���������� ������� A � B
    WaitForMultipleObjects(2, threads, TRUE, INFINITE);

    // ��������� ������� � ����������� �������
    CloseHandle(threads[0]);
    CloseHandle(threads[1]);
    CloseHandle(mutex);

    return 0;
}
