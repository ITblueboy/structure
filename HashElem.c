#include"HashElem.h"

void DestroyHashElem(HashElem *delete)
{
	if (delete == NULL)
	{
		return;
	}
	free(delete);
}
int HashBucketFindCurAndPre(HashElem *head, KeyType key, HashElem **_cur, HashElem **_pre)
{
	HashElem *pre = NULL;
	HashElem *cur = head;
	for (; cur != NULL; cur = cur->next)
	{
		if (cur->key == key)
		{
			*_cur = cur;
			*_pre = pre;
			return 1;
		}
	}
	return 0;
}
int Hash_funcDefault(KeyType key)
{
	return key%HashMaxSize;
}
HashElem *HashBucketFind(HashElem *head,KeyType key)
{
	HashElem *cur = head;
	for (; cur != NULL; cur = cur->next)
	{
		if (cur->key == key)
		{
			return cur;
		}
	}
	return NULL;
}
HashElem *CreateHashElem(KeyType key, ValType value)
{
	HashElem *new_node = (HashElem *)malloc(key);
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	return new_node;
}

void HashInit(HashTable *ht, HashFunc hash_func)
{
	if (ht == NULL)
	{
		return;
	}
	ht->size = 0;
	ht->hash_func = hash_func;
	return;
}
int  HashInsert(HashTable *ht, KeyType key, ValType value)
{
	if (ht == NULL)
	{
		return 0;
	}
	size_t offset = ht->hash_func(key);
	HashElem *result = HashBucketFind(ht->data[offset], key);
	if (result != NULL)
	{
		return 0;
	}
	else
	{
		HashElem *new_node = CreateHashElem(key, value);
		new_node->next = ht->data[offset];
		ht->data[offset] = new_node;
		++ht->size;
		return 1;
	}
}

int HashFind(HashTable *ht, KeyType key, ValType *value)
{
	if (ht == NULL || value == NULL)
	{
		return 0;
	}
	size_t offset = ht->hash_func(key);
	HashElem *result = HashBucketFind(ht->data[offset], key);
	if (result != NULL)
	{
		return result -> value;
	}
	else
	{
		return 0;
	}

}
void HashRemove(HashTable* ht, KeyType key)
{

	if (ht == NULL )
	{
		return ;
	}
	size_t offset = ht->hash_func(key);
	HashElem *cur = NULL;
	HashElem *pre = NULL;
	int ret= HashBucketFindCurAndPre(ht->data[offset], key,&cur,&pre);
	if (ret == 0)
	{
		return;
	}
	if (cur == ht->data[offset])
	{
		ht->data[offset] = cur->next;
	}
	else
	{
		pre->next = cur->next;
	}
	DestroyHashElem(cur);
	--ht->size;
	return;
}

size_t HashSize(HashTable* ht)
{
	if (ht == NULL)
	{
		return 0;
	}
	return ht->size;
}

int HashEmpty(HashTable* ht)
{
	if (ht == NULL)
	{
		return 1;
	}
	return ht->size > 0 ? 1 : 0;
}

void HashDestroy(HashTable* ht)
{
	if (ht == NULL)
	{
		return;
	}
	ht->size = 0;
	ht->hash_func = NULL;
	size_t i = 0;
	for (; i < HashMaxSize; i++)
	{
		HashElem *cur = ht->data[i];
		while (cur != NULL)
		{
			HashElem *to_delete = cur;
			cur = cur->next;
			DestroyHashElem(to_delete);
		}
	}
}
