#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq)
{
  if (pq == NULL)
  {
    return NULL;
  }
  
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap()
{
  Heap *nuevoHeap = (Heap *) malloc (sizeof(Heap));
  if (nuevoHeap == NULL)
  {
    return NULL;
  }

  nuevoHeap->capac = 3;
  nuevoHeap->heapArray = (heapElem*) malloc (nuevoHeap->capac * sizeof(heapElem));
  if (nuevoHeap->heapArray == NULL)
  {
    return NULL;
  }
  return nuevoHeap;
}
