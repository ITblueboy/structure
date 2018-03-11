#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

void Adjustdown(int array[], size_t length, size_t index)
{
	size_t parent=index;
	size_t child = 2 * parent + 1;
	while (child < length)
	{
		if (child + 1 < length&&array[child + 1] > array[child])
		{
			child = child + 1;
		}
		if (array[child])
	}
}



void HeapCreate(int array[], size_t length)
{
	size_t i = (length - 1 - 1) / 2;
	for (; i > 0; --i)
	{
		Adjustdown(array, length, i);
	}
	Adjustdown(array, length, 0);
}


void heapsort(int array[],size_t length)
{
	if (length <= 1)
	{
		return;
	}
	HeapCreate(array, length);
	size_t i = 0;
	for (; i < length - 1; i++)
	{
		HeapPop(array, length - 1);
	}
	return;
}