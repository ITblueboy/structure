#include"seqlist.h"
#include<assert.h>
#include<stdlib.h>

void SeqlistInit(seqlist* seq)
{
	assert(seq);
	seq->size = 0;
	seq->capacity = 1;
	seq->data = (seqType*)malloc(sizeof(seqType)*seq->capacity);
	return;
}

void SeqlistRealloc(seqlist* seq)
{
	seq->capacity = seq->capacity * 2 + 1;
	seqType* new_data = (seqType*)malloc(sizeof(seqType)*seq->capacity);
	size_t i = 0;
	for (; i < seq->size; ++i)
	{
		new_data[i] = seq->data[i];
	}
	free(seq->data);
	seq->data = new_data;
}
void SeqlistPushBack(seqlist* seq, seqType value)
{
	assert(seq);
	if (seq->size >= seq->capacity)
	{
		SeqlistRealloc(seq);
	}
	seq->data[seq->size++] = value;
	return;
}

void SeqlistPushFront(seqlist* seq, seqType value)
{
	assert(seq);
	if (seq->size >= seq->capacity)
	{
		SeqlistRealloc(seq);
	}
	if (seq->size == 0)
	{
		seq->data[0] = value;
		seq->size++;
		return;
	}
	size_t i = seq->size;
	seq->size++;
	for (; i > 0; i--)
	{
		seq->data[i + 1] = seq->data[i];
	}
	return;
}

void SeqlistPopBack(seqlist* seq)
{
	assert(seq);
	if (seq->size == 0)
	{
		return;
	}
	seq->size--;
	return;
}

void SeqlistPopFront(seqlist* seq)
{
	assert(seq);
	if (seq->size == 0)
	{
		return;
	}
	size_t i = 0;
	for (; i < seq->size; i++)
	{
		seq->data[i] = seq->data[i + 1];
	}
	seq->size--;
	return;
}

void SeqlistDestroy(seqlist* seq)
{
	assert(seq);
	seq->size = 0;
	seq->capacity = 0;
	free(seq->data);
}