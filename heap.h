#pragma once 

#include<stddef.h>
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>


#define HeapMaxSize 1000 
typedef int HeapType;

typedef int(*Compare)(HeapType a, HeapType b);

typedef struct Heap {
	HeapType data[HeapMaxSize];
	size_t size;
	Compare cmp;
} Heap;

void heapInit(Heap* heap, Compare compare);

void heapInsert(Heap* heap, HeapType value);

// 取堆顶元素 
int heapRoot(Heap* heap, HeapType* value);

// 删除堆顶元素 
void heapErase(Heap* heap);

int heapEmpty(Heap* heap);

size_t heapSize(Heap* heap);

void heapDestroy(Heap* heap);

// 在我们不想开辟额外的空间, 或者消耗额外的时间的前提下, 
// 如果我们想进行从小到大排序, 就需要一个大堆 
// 如果我们想进行从大到小排序, 就需要一个小堆 
void HeapSort(HeapType array[], size_t size);