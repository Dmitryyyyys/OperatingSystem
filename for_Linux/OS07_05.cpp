#include <stdio.h>
#include <time.h>

int main() {

	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	char buffer[80];
	strftime(buffer, 80, "%d.%m.%Y %H:%M:%S", timeinfo);
	printf("Текущая дата и время: %s \n", buffer)
		return 0;

}