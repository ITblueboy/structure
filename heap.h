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

// ȡ�Ѷ�Ԫ�� 
int heapRoot(Heap* heap, HeapType* value);

// ɾ���Ѷ�Ԫ�� 
void heapErase(Heap* heap);

int heapEmpty(Heap* heap);

size_t heapSize(Heap* heap);

void heapDestroy(Heap* heap);

// �����ǲ��뿪�ٶ���Ŀռ�, �������Ķ����ʱ���ǰ����, 
// �����������д�С��������, ����Ҫһ����� 
// �����������дӴ�С����, ����Ҫһ��С�� 
void HeapSort(HeapType array[], size_t size);