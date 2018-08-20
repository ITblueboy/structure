#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX_SIZE 100

typedef int SeqType;
typedef struct SeqList
{
  SeqType array[MAX_SIZE];
  size_t size;
}Seqlist;

void SeqlistInit(Seqlist* S);

void SeqlistPushBack(Seqlist* S, SeqType data);

void SeqlistPushFront(Seqlist* S, SeqType data);

void SeqlistPopFront(Seqlist* S);

void SeqlistPopBack(Seqlist* S);

void SeqlistInsert(Seqlist* S, size_t pos, SeqType data);

size_t SeqlistFind(Seqlist* S, SeqType to_find);

void SeqlistErase(Seqlist* S, size_t pos);

void SeqlistRemove(Seqlist* S, SeqType to_delete);

void SeqlistRemoveAll(Seqlist* S, SeqType to_delete);

size_t SeqlistSize(Seqlist* S);

int SeqlistEmpty(Seqlist* S);

void SeqlistBubbleSort(Seqlist* S);

void SeqlistSelectSort(Seqlist* S);

size_t SeqlistBinarySearch(Seqlist* S, SeqType value);

void SeqlistDestroy(Seqlist* S);



