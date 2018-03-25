#include<stdio.h>
#include<stdint.h>
#include<Windows.h>

void ShellSort(int array[], int64_t size)
{
	if (size <= 1)
	{
		return;
	}
	int64_t gap = size / 2;
	for (; gap > 0; gap /= 2)
	{
		int64_t bound = gap;
		for (; bound < size; bound++)
		{
			int value = array[bound];
			int64_t i = bound;
			for (; i >= gap; i -= gap)
			{
				if (array[i - gap]>value)
				{
					array[i] = array[i - gap];
				}
				else
				{
					break;
				}
			}
			array[i] = value;
		}
	}
	
}