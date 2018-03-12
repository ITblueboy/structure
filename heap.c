#include"heap.h"
#include<stdio.h>

void Adjustdown(HeapType data[], size_t size, Compare cmp, size_t index)
{
	size_t parent = index;
	size_t child = 2 * parent + 1;
	while (child < size)
	{
		if (child + 1 < size&&cmp(data[child + 1], data[child]))
		{
			child = child + 1;
		}
		if (cmp(data[child], data[parent]))
		{
			Swap(&data[child], data[parent]);
		}
		else
		{
			break;
		}
		parent = child;
		child = parent * 2 + 1;
	}
	return;
}
void Swap(HeapType *a, HeapType *b)
{
	HeapType *tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
void AdjustUp(HeapType data[], size_t size, Compare cmp, size_t index)
{
	if (index >= size)
	{
		return;
	}
	size_t child = index;
	size_t parent = (child - 1) / 2;
	while (child > 0)
	{
		if (cmp(data[child], data[parent]))
		{
			Swap(&data[child], data[parent]);
		}
		else
		{
			break;
		}
		child = parent;
		parent = (child - 1) / 2;
	}
	return;
}
void heapInit(Heap* heap, Compare compare)
{
	if (heap == NULL||compare==NULL)
	{
		return;
	}
	heap->size = 0;
	heap->cmp = compare;
	return;
}

void heapInsert(Heap* heap, HeapType value)
{
	if (heap == NULL)
	{
		return;
	}
	if (heap->size >= HeapMaxSize)
	{
		return;
	}
	heap->data[heap->size++] = value;
	AdjustUp(heap->data, heap->size, heap->cmp, heap->size - 1);
}

// 取堆顶元素 
int HeapRoot(Heap* heap, HeapType* value)
{
	if (heap == NULL)
	{
		return 0;
	}
	if (heap->size == 0)
	{
		return 0;
	}
	*value = heap->data[0];
	return 1;
}

// 删除堆顶元素 
void heapErase(Heap* heap)
{
	if (heap == NULL)
	{
		return;
	}
	if (heap->size == 0)
	{
		return;
	}
	Swap(&heap->data[0], &heap->data[heap->size - 1]);
	--heap->size;
	Adjustdown(heap->data, heap->size, heap->cmp, 0);
}

int heapEmpty(Heap* heap)
{
	if (heap == NULL)
	{
		return 1;
	}
	if (heap->size == 0)
	{
		return 1;
	}
	return -1;
}

 size_t heapSize(Heap* heap)
{
	if (heap == NULL)
	{
		return 0;
	}
	return heap->size;
}

void heapDestroy(Heap* heap)
{
	if (heap == NULL)
	{
		return;
	}
	heap->size = 0;
}

// 在我们不想开辟额外的空间, 或者消耗额外的时间的前提下, 
// 如果我们想进行从小到大排序, 就需要一个大堆 
// 如果我们想进行从大到小排序, 就需要一个小堆 
void Adjustdown(int array[], size_t length, size_t index)
{
	size_t parent = index;
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


void heapsort(int array[], size_t length)
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