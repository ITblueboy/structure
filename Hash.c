#include"Hash.h"


void HashPrint(HashTable *ht)
{
	size_t i = 0;
	for (i = 0; i < HashMaxSize; i++)
	{
		for (; i < HashMaxSize; i++)
		{
			if (ht->data[i].stat != Empty)
			{
				printf("[%lu]key=%d,value=%d\n", i, ht->data[i].key, ht->data[i].value);
			}
		}
	}
}
size_t HashFuncDefault(KeyType key)
{
	return key % HashMaxSize;
}

void HashInit(HashTable* ht, HashFunc key)
{
	if (ht == NULL)
	{
		return;
	}
	ht->size= 0;
	size_t i = 0;
	for (i = 0; i < HashMaxSize; i++)
	{
		ht->data[i].stat = Empty;
	}
}

int HashInsert(HashTable* ht, KeyType key, ValType value)
{
	if (ht == NULL)
	{
		return 0;
	}
	if (ht->size >= HashMaxSize*0.9)
	{
		return 0;
	}
	size_t offset = ht->hash_func(key);
	while (1)
	{
		if (ht->data[offset].stat == Valid)
		{
			++offset;
			if (offset >= HashMaxSize)
			{
				offset -= HashMaxSize;
			}
		}
		else
		{
			ht->data[offset].key = key;
			ht->data[offset].value = value;
			ht->data[offset].stat = Valid;
			return 1;
		}
	}
	return 0;
}

// 输入key, 查找对应key的value. 
int HashFind(HashTable* ht, KeyType key, ValType* value)
{
	if (ht == NULL || key == NULL)
	{
		return 0;
	}
	size_t offset = HashFuncDefault(key);
	while (1)
	{
		if (ht->data[offset].key == key&&ht->data[offset].stat == Valid)
		{
			*value = ht->data[offset].value;
			return value;
		}
		else if (ht->data[offset].stat == Empty)
		{
			return 0;
		}
		else
		{
			++offset;
			if (offset >= HashMaxSize)
			{
				offset -= HashMaxSize;
			}
		}
	}
	return 0;
}

void HashRemove(HashTable* ht, KeyType key)
{
	if (ht == NULL)
	{
		return;
	}
	size_t offset = HashFuncDefault(key);
	while (1)
	{
		if (ht->data[offset].key == key&&ht->data[offset].stat == Valid)
		{
			ht->data[offset].stat = Invalid;
		}
		if (ht->data[offset].stat == Empty)
		{
			return;
		}
		else
		{
			++offset;
			if (offset >= HashMaxSize)
			{
				offset -= HashMaxSize;
			}
		}
	}
	return;
}

int HashEmpty(HashTable* ht)
{
	if (ht == NULL)
	{
		return;
	}
	int i = 0;
	for (; i < HashMaxSize; i++)
	{
		if (ht->data[i].stat != Empty)
		{
			return 0;
		}
	}
	return 1;
}

size_t HashSize(HashTable* ht)
{
	int sum = 0;
	if (ht == NULL)
	{
		return;
	}
	for (int i=0; i < HashMaxSize; i++)
	{
		if (ht->data[i].stat==Valid)
		{
			sum++;
		}
	}
	return sum;
}
void HashDestroy(HashTable* ht)
{
	if (ht == NULL)
	{
		return;
	}
	for (int i = 0; i < HashMaxSize; i++)
	{
		ht->data[i].stat == Empty;
	}
}

void CountNum(HashTable *ht)
{
	if (ht == NULL)
	{
		return;
	}
	int arr[] = { 1, 1, 1, 2, 2, 3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	HashTable ht;
	for (int i = 0; i < len; i++)
	{
		int value = 0;
		int ret = HashFind(&ht, arr[i], &value);
		if (ret == 0)
		{
			HashInsert(&ht, arr[i], i);
		}
		else
		{
			HashRemove(&ht, arr[i],i);
			HashInsert(&ht, arr[i], i);
			value++;
		}
	}
	HashPrint(&ht);
}