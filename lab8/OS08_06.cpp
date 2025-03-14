#include <iostream>

int main() {
    volatile long long counter = 0;

    // Длинный цикл
    while (true) {
        counter++;
        if (counter % 1000000000 == 0) {
            std::cout << "Counter: " << counter << std::endl;
        }
    }

    return 0;
}
