#include"BitMap.h"
#include<stdlib.h>


size_t Datasize(size_t capacity)
{
	return capacity / (8 * sizeof(uint64_t)) + 1;
}

void GetOffset(size_t index, size_t *n, size_t *offset)
{
	*n = index / (sizeof(uint64_t) * 8);
	*offset = index % (8 * sizeof(uint64_t));
}
void BitMapInit(BitMap* bm, size_t capacity)
{
	if (bm == NULL)
	{
		return;
	}
	bm->capacity = capacity;
	size_t size = DataSize(capacity);
	bm->data = (uint64_t *)malloc(sizeof(uint64_t)*size);
}

// 把第 index 位置为1 
void BitMapSet(BitMap* bm, size_t index)
{
	if (bm == NULL)
	{
		return;
	}
	if (index >= bm->capacity)
	{
		return;
	}
	size_t n, offset;
	Getoffset(index, &n, &offset);
	bm->data[n] |= (1ul << offset);
}

// 把第 index 位置为0 
void BitMapUnset(BitMap* bm, size_t index)
{
	if (bm == NULL)
	{
		return;
	}
	if (index >= bm->capacity)
	{
		return;
	}
	size_t n, offset;
	Getoffset(index, &n, &offset);
	bm->data[n] &= (1ul << offset);
}

// 测试 index 为是 1 , 还是 0. 如果是1, 就返回1. 否则返回0. 
int BitMapTest(BitMap* bm, size_t index)
{
	if (bm == NULL)
	{
		return;
	}
	if (index >= bm->capacity)
	{
		return;
	}
	size_t n, offset;
	Getoffset(index, &n, &offset);
	uint64_t ret = (bm->data[n] & (1ul << offset));
	return ret != 0 ? 1 : 0;
}

// 把整个位图所有的位都设为1. 
void BitMapFill(BitMap* bm)
{
	if (bm == NULL)
	{
		return;
	}
	size_t n, offset;
	for (; n < bm->capacity; n++)
	{

		bm->data[n] |= (1ul << offset);
	}
	return;
}

// 把整个位图所有的位都设为0. 
void BitMapClear(BitMap* bm)
{
	if (bm == NULL)
	{
		return;
	}
	size_t n, offset;
	for (; n < bm->capacity; n++)
	{
		bm->data[n] &= (1ul << offset);
	}
	return;
}

void BitMapDestroy(BitMap* bm)
{
	bm->data = NULL;
}