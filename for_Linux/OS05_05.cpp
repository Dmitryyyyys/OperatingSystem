#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    // ��������� �������������� �������� ��������
    pid_t pid = getpid();
    // ��������� �������������� �������� ������ (main thread)
    pthread_t tid = pthread_self();
    // ��������� �������� ���������� (nice)
    int nice_value = getpriority(PRIO_PROCESS, pid);

    printf("������������� ��������: %d\n", pid);
    printf("������������� ������ (main): %lu\n", (unsigned long)tid);
    printf("������� ��������� (nice): %d\n", nice_value);

    // ������� ����
    for (long i = 0; i < 1000000000; i++) {
        // ����� �������� ��������, ����� ���������� �� ������������ 100% CPU
        // usleep(1); // 1 ������������
    }

    return 0;
}
