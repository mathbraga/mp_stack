#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/pilha.hpp"

Pilha *CreateStack(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    
    if(p == NULL)
        return NULL;

    p->items = (ItemType*)malloc(sizeof(ItemType)*SIZE);

    if(p->items == NULL)
        return NULL;

    p->top = 0;

    return p;
}

void DestroyStack(Pilha **p){
    Pilha *aux;
    aux = *p;
    free(aux->items);
    aux->items = NULL;
    free(*p);
    *p = NULL;
}

int IsEmpty(Pilha *p){
    if((p->top) == 0)
        return TRUE;
    else
        return FALSE;  
}

int IsFull(Pilha *p){
    if((p->top) >= SIZE)
        return TRUE;
    else
        return FALSE;    
}

int SetSize(Pilha *p, int new_size){
    //assumi que para a implementação com vetor a pilha tem tamanho fixo
    //logo não se pode mudar o tamanho dela despois que já foi criada
    return FALSE;
}

int Size(Pilha *p){
    return p->top;
}

ItemType Top(Pilha *p){
    return p->items[(p->top)-1];
}

ItemType Pop(Pilha *p){
    if(IsEmpty(p)){
        perror("Erro! Pilha vazia!");
        exit(1);
    }
    ItemType ret;
    ret = p->items[(p->top)-1];
    p->top--;
    return ret;
}

void Push(Pilha *p, ItemType elem){
    if(!IsFull(p)){
        p->items[p->top] = elem;
        p->top++;
    }
    else{
        perror("Erro! Pilha cheia!");
        exit(1);
    }
}