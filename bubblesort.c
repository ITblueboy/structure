#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"


void bubblesort(int array[], int len)
{
	int i = 0, j = 0;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				Swap(array[j], array[j + 1]);
			}
		}
	}
	myprintf(array,len);
}