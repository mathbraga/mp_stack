#ifndef PILHA_INCLUDE_PILHA_H_
#define PILHA_INCLUDE_PILHA_H_

#include <stdio.h>
#include <stdlib.h>
#include "TipoPilha.hpp"

Pilha *CreateStack();        // Cria pilha
void DestroyStack(Pilha**);  // Destroi pilha
int IsEmpty(Pilha*);         // Verifica se pilha está vazia
int IsFull(Pilha*);          // Verifica se pilha está cheia
int SetSize(Pilha*, int);    // Emprega um tamanho para pilha com vetor
int Size(Pilha*);            // Retorna o tamanho da pilha
ItemType Top(Pilha*);        // Retorna o elemento do topo da pilha
ItemType Pop(Pilha*);        // Retira o elemento do topo da pilha
void Push(Pilha*, ItemType); // Insere um elemento no topo da pilha

#endif  // PILHA_INCLUDE_PILHA_H_