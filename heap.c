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
    pq->capac = 2 * pq->capac + 1;
    pq->heapArray = (heapElem *) realloc (pq->heapArray, pq->capac * sizeof(heapElem));
    if (pq->heapArray == NULL)
    {
      return;
    }
  }

  heapElem nuevoElem;
  nuevoElem.data = data;
  nuevoElem.priority = priority;

  int indiceActual = pq->size;
  int indicePadre = ((indiceActual - 1) / 2);

  while (indiceActual > 0 && pq->heapArray[indicePadre].priority < nuevoElem.priority)
    {
      pq->heapArray[indiceActual] = pq->heapArray[indicePadre];
      indiceActual = indicePadre;
      indicePadre = ((indiceActual - 1) / 2);
    }
  pq->heapArray[indiceActual] = nuevoElem;
  pq->size++;
}


void heap_pop(Heap* pq)
{
  if (pq == NULL || pq->size == 0)
  {
    return;
  }

  pq->heapArray[0] = pq->heapArray[pq->size - 1];
  pq->size--;

  int indice = 0;
  while (1)
    {
      int hijoIzquierdo = 2 * indice + 1;
      int hijoDerecho = 2 * indice + 2;
      int menorPrioridad = indice;

      if (hijoIzquierdo < pq->size && pq->heapArray[hijoIzquierdo].priority < pq->heapArray[menorPrioridad].priority)
      {
        menorPrioridad = hijoIzquierdo;
      }
      if (hijoDerecho < pq->size && pq->heapArray[hijoDerecho].priority < pq->heapArray[menorPrioridad].priority)
      {
        menorPrioridad = hijoDerecho;
      }
      if (menorPrioridad != indice)
      {
        heapElem temporal = pq->heapArray[indice];
        pq->heapArray[indice] = pq->heapArray[menorPrioridad];
        pq->heapArray[menorPrioridad] = temporal;
        indice = menorPrioridad;
      }
      else
      {
        break;
      }
    }
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
