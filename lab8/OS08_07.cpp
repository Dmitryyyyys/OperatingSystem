#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstring>

int main()
{
	size_t memSize = 256 * 1024 * 1024;
	int* array = (int*)malloc(memSize);
	if (array == nullptr)
	{
		std::cerr << "Ошибка выделения памяти" << std::endl;
		return 1;
	}
	size_t countItems = memSize / sizeof(int);
	for (size_t i = 0; i < countItems; ++i)
	{
		array[i] = i;
	}
	std::cout << "Address vydelynoy pamyati: " << static_cast<void*>(array) << std::endl;
	std::cout << "Ostanovka 60s... " << std::endl;
	sleep(60);

	free(array);
	return 0;
}