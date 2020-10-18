#ifndef PILHA_INCLUDE_PILHA_H_
#define PILHA_INCLUDE_PILHA_H_

#include <stdio.h>
#include <stdlib.h>
#include "TipoPilha.hpp"

typedef struct{
    ItemType *items;
    int top;
}Pilha;

Pilha *CreateStack();
void DestroyStack(Pilha**);
int IsEmpty(Pilha*);
int IsFull(Pilha*);
int SetSize(Pilha*, int);
int Size(Pilha*);
ItemType Top(Pilha*);
ItemType Pop(Pilha*);
void Push(Pilha*, ItemType);

#endif  // PILHA_INCLUDE_PILHA_H_