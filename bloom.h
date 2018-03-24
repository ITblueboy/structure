#pragma once 
#include "BitMap.h"
#include<stdio.h>
#include<stddef.h>
#include<stdint.h>



#define HashFuncMaxSize 2 
#define BitMapCapcity 1024 

typedef size_t(*HashFunc)(const char*);

typedef struct BloomFilter {
	BitMap bitmap;
	HashFunc hash_func[HashFuncMaxSize];
} BloomFilter;

void BloomFilterInit(BloomFilter* bf);

void BloomFilterInsert(BloomFilter* bf, const char* str);

int BloomFilterIsExist(BloomFilter* bf, const char* str);

void BloomFilterDestroy(BloomFilter* bf);

// ���յ�ǰ�����, �ǲ�����ɾ����.
