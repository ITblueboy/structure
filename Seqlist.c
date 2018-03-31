#include"Seqlist.h"
#include<stdio.h>
#include<assert.h>

void Swap(SeqType* a, SeqType* b)
{
	assert(a);
	assert(b);
	SeqType tmp = *a;
	*a = *b;
	*b = tmp;
}
void SeqlistInit(Seqlist* S)
{
	assert(S);
	S->size = 0;
	return;
}


void SeqlistPushBack(Seqlist* S, SeqType data)
{
	assert(S);
	if (S->size >= SeqlistMaxSize)
	{
		return;
	}
	S->data[S->size++] = data;
	return;
}

void SeqlistPushFront(Seqlist* S, SeqType data)
{
	assert(S);
	if (S->size >= SeqlistMaxSize)
	{
		return;
	}
	size_t i = S->size-1;
	while (i >= 0)
	{
		S->data[i + 1] = S->data[i];
		i--;
	}
	S->data[0] = data;
	S->size++;
}

void SeqlistPopFront(Seqlist* S)
{
	assert(S);
	if (S->size == 0);
	{
		return;
	}
	size_t i = 0;
	while (i < S->size)
	{
		S->data[i] = S->data[i + 1];
		i++;
	}
	S->size--;
	return;
}

void SeqlistPopBack(Seqlist* S)
{
	assert(S);
	if (S->size == 0)
	{
		return;
	}
	S->size--;
	return;
}

void SeqlistInsert(Seqlist* S, size_t pos, SeqType data)
{
	assert(S);
	if (S->size >= SeqlistMaxSize)
	{
		return;
	}
	if (pos > S->size)
	{
		return;
	}
	
	++S->size;
	size_t i = S->size - 1;
	for (; i < pos; --i)
	{
		S->data[i] = S->data[i - 1];
	}
	S->data[pos] = data;
	return;
}

size_t SeqlistFind(Seqlist* S, SeqType to_find)
{
	assert(S);
	if (S->size == 0)
	{
		return;
	}
	size_t i = 0;
	for (; i < S->size; i++)
	{
		if (S->data[i] == to_find)
		{
			return i;
		}
	}
	return (size_t)-1;
}

void SeqlistErase(Seqlist* S, size_t pos)
{
	assert(S);
	if (S->size == 0)
	{
		return;
	}
	if (pos >= S->size)
	{
		return;
	}
	size_t i = pos;
	for (; i < S->size - 1; i++)
	{
		S->data[i] = S->data[i + 1];
	}
	--S->size;
}

void SeqlistRemove(Seqlist* S, SeqType to_delete)
{
	assert(S);
	
	size_t pos = SeqlistFind(S, to_delete);
	if (pos == (size_t)-1)
	{
		return;
	}
	SeqlistErase(S, pos);
}

void SeqlistRemoveAll(Seqlist* S, SeqType to_delete)
{
	assert(S);
	while (1)
	{
		size_t pos = SeqlistFind(S, to_delete);
		if (pos == (size_t)-1)
		{
			break;
		}
		SeqlistErase(S, pos);
	}
	return;
}

size_t SeqlistSize(Seqlist* S)
{
	assert(S);
	return S->size;
}

int SeqlistEmpty(Seqlist* S)
{
	assert(S);
	if (S->size == 0)
	{
		return 1;
	}
	return 0;
}

void SeqlistBubbleSort(Seqlist* S)
{
	assert(S);
	size_t i = 0;
	size_t j = 0;
	for (; i < S->size-1; i++)
	{
		for (; j < S->size - i - 1; j++)
		{
			if (S->data[j]>S->data[j + 1])
			{
				Swap(&S->data[j], &S->data[j + 1]);
			}
		}
	}
}

void SeqlistSelectSort(Seqlist* S)
{
	assert(S);
	size_t min_pos = 0;
	for (; min_pos < S->size; ++min_pos)
	{
		size_t cur = min_pos;
		for (; cur < S->size; ++cur)
		{
			if (S->data[cur]>S->data[min_pos])
			{
				Swap(&S->data[cur], &S->data[min_pos]);
			}
		}
	}
	return;
}

size_t SeqlistBinarySearch(Seqlist* S, SeqType value)
{
	assert(S);
	size_t begin = 0;
	size_t end = S->size;
	while (begin<end)
	{
		size_t mid = begin + (end - begin) / 2;
		if (S->data[mid]>value)
		{
			end = mid;
		}
		if (S->data[mid] < value)
		{
			begin = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return (size_t)-1;
}

void SeqlistDestroy(Seqlist* S)
{
	assert(S);
	S->size = 0;
	return;
}