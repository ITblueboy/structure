#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"



void insertsort(int array[], int length)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < length; i++)
	{
		if (array[i] < array[i - 1])
		{
			int tmp = array[i];
			for (j = i - 1; j >= 0 && array[j] > tmp; j--)
			{
				array[j] = array[j+i];
				array[j + 1] = tmp;
			}
		}
	}
	myprintf(array, length);
	{
}