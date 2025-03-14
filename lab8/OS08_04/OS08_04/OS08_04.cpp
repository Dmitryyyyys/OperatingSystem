#include<iostream>
#include<Windows.h>
using namespace std;
void sh(HANDLE heap)
{
	SetConsoleOutputCP(1251);
	PROCESS_HEAP_ENTRY entry;
	entry.lpData = NULL;
	SIZE_T totalSize = 0, allocatedSize = 0, unallocatedSize = 0;

	while (HeapWalk(heap, &entry) != FALSE)
	{
		totalSize += entry.cbData;
		if (entry.wFlags & PROCESS_HEAP_ENTRY_BUSY)
		{
			allocatedSize += entry.cbData;
		}
		else
		{
			unallocatedSize += entry.cbData;
		}
	}

	cout << "Общий размер heap: " << totalSize << endl;
	cout << "Размер распределенной памяти heap: " << allocatedSize << endl;
	cout << "Размер нераспределенной памяти heap: " << unallocatedSize << endl;

}
int main()
{

	HANDLE heap = GetProcessHeap();
	sh(heap);
	const int ARRAYSIZE = 300000;
	int* array = new int[ARRAYSIZE];
	sh(heap);
	delete[] array;
	return 0;
}
