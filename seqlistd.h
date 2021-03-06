#pragma once 
#include<stddef.h>

typedef char seqType;

typedef struct seqlist
{
	seqType* data;
	size_t size;
	size_t capacity;

}seqlist;

void SeqlistInit(seqlist* seq);

void SeqlistPushBack(seqlist* seq, seqType value);

void SeqlistPushFront(seqlist* seq, seqType value);

void SeqlistPopBack(seqlist* seq);

void SeqlistPopFront(seqlist* seq);

void SeqlistDestroy(seqlist* seq);