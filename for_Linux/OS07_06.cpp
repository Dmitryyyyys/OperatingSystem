#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
	long long counter = 0;
	clock_t start_time, current_time;
	struct timespec start_real_time, current_real_time;
	start_time = clock();
	clock_gettime(CLOCK_REALTIME, &start_real_time);
	while (1) {
		counter++;
		current_time = clock();
		if ((double)current_time - start_time) / CLOCKS_PER_SEC >= 2.0){
		printf("Итерации: %lld\n", counter);
		break;

		clock_gettime(CLOCK_REALTIME, &current_real_time);
		double real_time_elapsed = (current_real_time.tv_sec - start_real_time.tv_sec) +
			(current_real_time.tv_nsec - start_real_time.tv_nsec) / 1e9;
		printf("Затраченное реальное время: %.6f секунд\n", real_time_elapsed);

		return 0;
}
	}

}
