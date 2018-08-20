#include"sheet.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

void seqlistRealloc(seqlist* seq)
{
  seq->capacity=seq->capacity*2+1;
  seqType* new_list=(seqType*)malloc(sizeof(seqType)*seq->capacity);
  int i=0;
  while(i<=(int)seq->size)
  {
    new_list[i]=seq->data[i];
  }
  free(seq->data);
  seq->data=new_list;
}

void SeqlistInit(seqlist* seq)
{
  assert(seq);
  seq->size=0;
  seq->capacity=1;
  seq->data=(seqType*)malloc(sizeof(seqType)*(seq->capacity));
}

void SeqlistPushBack(seqlist* seq, seqType value)
{
  assert(seq);
  if(seq->size>=seq->capacity)
  {
    seqlistRealloc(seq);
  }
  seq->data[seq->size++]=value;
  return;
}

void SeqlistPushFront(seqlist* seq, seqType value)
{
  assert(seq);
  if(seq->size>=seq->capacity)
  {
    seqlistRealloc(seq);
  }
  if(seq->size==0)
  {
    seq->data[seq->size++]=value;
    return;
  }
  int i=seq->size;
  while(i>=0)
  {
    seq->data[i+1]=seq->data[i];
    i--;
  }
  seq->data[i]=value;
  seq->size++;
  return;
}

void SeqlistPopBack(seqlist* seq)
{
  assert(seq);
  if(seq->size==0)
  {
    return;
  }
  seq->size--;
  return;
}

void SeqlistPopFront(seqlist* seq)
{
  assert(seq);
  if(seq->size==0)
  {
    return;
  }
  int i=0;
  while(i<(int)seq->size)
  {
    seq->data[i]=seq->data[i+1];
    i++;
  }
  seq->size--;
  return;
}

size_t SeqlistFind(seqlist* seq,seqType value)
{
  assert(seq);
  int i=0;
  while(i<=(int)seq->size)
  {
    if(seq->data[i]==value)
    {
      return (size_t)i;
    }
    i++;
  }
  return (size_t)-1;
}

void SeqlistErase(seqlist* seq,seqType value)
{
  assert(seq);
  if(seq->size==0)
  {
    return;
  }
  size_t i=0;
  while(i<=seq->size)
  {
    if(seq->data[i]==value)
    {
      if(i==seq->size)
      {
        SeqlistPopBack(seq);
      }
      while(i<seq->size)
      {
        seq->data[i]=seq->data[i+1];
        i++;
      }
      return;
    }
    i++;
  }
  return;
}

void SeqlistDestroy(seqlist* seq)
{
  assert(seq);
  seq->size=0;
  seq->capacity=0;
  free(seq->data);
  return;
}
