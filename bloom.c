#include"boolm.h"

size_t HashFunc0(const char* str)
{
	size_t hash = 0;
	size_t ch ;
	while (ch = (size_t)*str++)
	{
		hash = hash * 131 + ch;
	}
	return hash;
}
size_t HashFunc1(const char* str)
{
	size_t hash = 0;
	size_t ch;
	while (ch = (size_t)*str++)

	{
		hash = 65599 * hash + ch;

	}
	return hash;
}
void BloomFilterInit(BloomFilter* bf)
{
	BitMapInit(&bf->bitmap.Capcity);
	bf->hash_func[0] = HashFunc0;
	bf->hash_func[1] = HashFunc1;
}

void BloomFilterInsert(BloomFilter* bf, const char* str)
{
	if(bf == NULL || str == NULL)
	{
		return;
	}
	size_t i = 0;
	for (; i < HashFuncMaxSize; i++)
	{
		size_t offset = bf->hash_func[i](str) % BitMapCapcity;
		BitMapSet(&bf->bitmap, offset);
	}
	return;
}

int BloomFilterIsExist(BloomFilter* bf, const char* str)
{
	if(bf == NULL || str == NULL)
	{
		return 0;
	}
	size_t i = 0;
	for (; i< HashFuncMaxSize; i++)
	{
		size_t offset = bf->hash_func[i](str) % BitMapCapcity;
		int ret = BitMapTest(&bf->bitmap, offset);
		if (ret == 0)
		{
			return 0;
		}
	}
	return 1;
}

void BloomFilterDestroy(BloomFilter* bf)
{
	if (bf == NULL)
	{
		return;
	}
	BitMapDestroy(&bf->bitmap);
	bf->hash_func[0] = NULL;
	bf->hash_func[1] = NULL;
	return;
}