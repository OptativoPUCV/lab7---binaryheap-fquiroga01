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
  if (pq == NULL || pq->size == 0)
  {
    return NULL;
  }
  
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority)
{
  if (pq == NULL)
  {
    return;
  }

  if (pq->size >= pq->capac)
  {
    pq->capac = pq->capac * 2 + 1;
    pq->heapArray = (heapElem *) realloc (pq->heapArray, pq->capac * sizeof(heapElem));
    if (pq->heapArray == NULL)
    {
      return;
    }
  }

  heapElem nuevoElem;
  nuevoElem.data = data;
  nuevoElem.priority = priority;

  int indice = pq->size;
  pq->heapArray[indice] = nuevoElem;
  pq->size++;

  while (indice > 0)
  {
    int indicePadre = (indice - 1);
    if (pq->heapArray[indice].priority < pq->heapArray[indicePadre].priority)
    {
      heapElem temporal = pq->heapArray[indice];
      pq->heapArray[indice] = pq->heapArray[indicePadre];
      pq->heapArray[indicePadre] = temporal;
      indice = indicePadre;
    }
    else
    {
      break;
    }
  }
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
