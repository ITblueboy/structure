#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

void selectsort(int array[], int length)
{
	int i = 0, j = 0;
	for (i = 0; i < length; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (array[i] > array[j])
			{
				Swap(array[i], array[j]);
			}
		}
	}
	myprintf(array, length);
}