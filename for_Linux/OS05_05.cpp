#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    // Получение идентификатора текущего процесса
    pid_t pid = getpid();
    // Получение идентификатора текущего потока (main thread)
    pthread_t tid = pthread_self();
    // Получение текущего приоритета (nice)
    int nice_value = getpriority(PRIO_PROCESS, pid);

    printf("Идентификатор процесса: %d\n", pid);
    printf("Идентификатор потока (main): %lu\n", (unsigned long)tid);
    printf("Текущий приоритет (nice): %d\n", nice_value);

    // Длинный цикл
    for (long i = 0; i < 1000000000; i++) {
        // Можно добавить задержку, чтобы приложение не использовало 100% CPU
        // usleep(1); // 1 микросекунда
    }

    return 0;
}
