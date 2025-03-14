#include <iostream>
#include <thread>
#include <vector>
#include <sched.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    // Получаем идентификатор текущего процесса
    pid_t pid = getpid();

    // Получаем идентификатор текущего потока
    std::thread::id thread_id = std::this_thread::get_id();

    // Получаем приоритет (nice) текущего потока
    int nice_value = nice(0); // Передаем 0, чтобы получить текущий приоритет

    // Получаем количество доступных процессоров
    int num_processors = sysconf(_SC_NPROCESSORS_ONLN);

    // Выводим информацию на консоль
    std::cout << "Current process ID: " << pid << std::endl;
    std::cout << "Current thread ID: " << thread_id << std::endl;
    std::cout << "Current thread priority (nice): " << nice_value << std::endl;

    std::cout << "Available processors: ";
    for (int i = 0; i < num_processors; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
