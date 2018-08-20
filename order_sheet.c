#include"order_sheet.h"

void swap(SeqType* a,SeqType* b)
{
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

void myprintf(Seqlist* S)
{
  int i=0;
  for(;i<=(int)S->size;i++)
  {
    printf("%d ",S->array[i]);
  }
  printf("\n");
}

void SeqlistInit(Seqlist* S)
{
  assert(S);
  S->size=0;
  return;
}

void SeqlistPushBack(Seqlist* S, SeqType data)
{
  assert(S);
  if(S->size<MAX_SIZE)
  {
    S->array[S->size++]=data;
  }
  myprintf(S);
  return;
}

void SeqlistPushFront(Seqlist* S, SeqType data)
{
  assert(S);
  if(S->size>=MAX_SIZE)
  {
    return;
  }
  S->size++;
  int i=(int)(S->size)-1;
  for(;i>=0;i--)
  {
    S->array[i+1]=S->array[i];
  }
  S->array[i]=data;
  myprintf(S);
  return;
}

void SeqlistPopFront(Seqlist* S)
{
  assert(S);
  int i=1;
  if(S->size==0)
  {
    return;
  }
  while(i<=(int)S->size)
  {
    S->array[i-1]=S->array[i];
    i++;
  }
  S->size--;
  myprintf(S);
  return;
}

void SeqlistPopBack(Seqlist* S)
{
  assert(S);
  if(S->size==0)
  {
    return;
  }
  S->size--;
  myprintf(S);
  return;
}

void SeqlistInsert(Seqlist* S, size_t pos, SeqType data)
{
  assert(S);
  if(S->size>=MAX_SIZE)
  {
    return;
  }
  if(pos>MAX_SIZE)
  {
    return;
  }
  S->size++;
  int i=(int)(S->size)-1;
  while(i>=(int)pos)
  {
    S->array[i+1]=S->array[i];
    i--;
  }
  S->array[pos]=data;
  myprintf(S);
  return;
}

size_t SeqlistFind(Seqlist* S, SeqType to_find)
{
  assert(S);
 int i=0;
 while(i<=(int)S->size)
 {
   if(S->array[i]==to_find)
   {
     return (size_t)i;
   }
   i++;
 }
 return size_t(-1);
}

void SeqlistErase(Seqlist* S, size_t pos)
{
  assert(S);
  if(pos>MAX_SIZE)
  {
    return;
  }
  int i=pos;
  while(i<(int)(S->size-1))
  {
    S->array[i]=S->array[i+1];
    i++;
  }
  S->size--;
  myprintf(S);
  return;
}

void SeqlistRemove(Seqlist* S, SeqType to_delete)
{
  assert(S);
  int i=0;
  while(i<=(int)S->size)
  {
    if(S->array[i]==to_delete)
    {
      SeqlistErase(S,(size_t)i);
      return;
    }
    i++;
  }
  myprintf(S);
}

void SeqlistRemoveAll(Seqlist* S, SeqType to_delete)
{
  assert(S);
  int i=0;
  while(i<(int)(S->size)-1)
  {
    if(S->array[i]==to_delete)
    {
      SeqlistErase(S,(size_t)i);
    }
    i++;
  }
  myprintf(S);
}

size_t SeqlistSize(Seqlist* S)
{
  assert(S);
  return S->size;
}

int SeqlistEmpty(Seqlist* S)
{
  assert(S);
  if(S->size==0)
  {
    return 1;
  }
  return 0;
}

void SeqlistBubbleSort(Seqlist* S)
{
  assert(S);
  int count=(int)S->size;
  int i=0;
  int j=0;
  for(;i<=count;i++)
  {
    for(j=i;j<count-i;j++)
    {
      if(S->array[j]>S->array[j+1])
      {
        swap(&S->array[j],&S->array[j+1]);
      }
    }
  }
  myprintf(S);
}

void SeqlistSelectSort(Seqlist* S);

size_t SeqlistBinarySearch(Seqlist* S, SeqType value)
{
  assert(S);
  if(S->size==0)
  {
    return (size_t)-1;
  }
  int begin=0;
  int end=S->size;
  int mid=0;
  while(end>begin)
  {
    mid=begin+(end-begin)/2;
    if(S->array[mid]==value)
    {
      return mid;
    }
    else if(S->array[mid]>value)
    {
      begin=mid+1;
    }
    else 
      end=mid-1;
  }
  return (size_t)-1;
}

void SeqlistDestroy(Seqlist* S)
{
  S->size=0;
  S=NULL;
}

