// Copyright 2020 Matheus Braga
#include <stdio.h>
#include <stdlib.h>
#include "../include/TipoPilha.hpp"
#include "../include/pilha.hpp"

// Cria pilha
Pilha *CreateStack() {
    Pilha *p = reinterpret_cast<Pilha*>(malloc(sizeof(Pilha)));

    if (p == nullptr) {
        perror("Erro na alocação de memoria!");
        return nullptr;
    }

    p->items = nullptr;
    p->tamanho = 0;
    p->top = 0;

    return p;
}

// Destroi pilha
void DestroyStack(Pilha **p) {
    free(*p);
    *p = nullptr;
}

// Verifica se pilha está vazia
int IsEmpty(Pilha *p) {
    if ((p->top) == 0)
        return TRUE;
    else
        return FALSE;
}

// Verifica se pilha está cheia
int IsFull(Pilha *p) {
    if (IsEmpty(p))
        return FALSE;
    else if ((p->top) >= Size(p))
        return TRUE;
    else
        return FALSE;
}

// Emprega um tamanho para pilha com vetor
int SetSize(Pilha *p, int new_size) {
    p->tamanho = new_size;
    if (p->items == nullptr) {
        p->items = reinterpret_cast<ItemType*>\
        (malloc(sizeof(ItemType)*p->tamanho));
    } else {
        p->items = reinterpret_cast<ItemType*>\
        (realloc(p->items, sizeof(ItemType)*p->tamanho));
    }
    if (p->items != nullptr)
        return TRUE;
    else
        return FALSE;
}

// Retorna o tamanho da pilha
int Size(Pilha *p) {
    return p->tamanho;
}

// Retorna o elemento do topo da pilha
ItemType Top(Pilha *p) {
    return p->items[(p->top)-1];
}

// Retira o elemento do topo da pilha
ItemType Pop(Pilha *p) {
    if (IsEmpty(p)) {
        perror("Erro! Pilha vazia!");
        exit(1);
    }
    ItemType ret;
    ret = p->items[(p->top)-1];
    p->top--;
    return ret;
}

// Insere um elemento no topo da pilha
void Push(Pilha *p, ItemType elem) {
    if (!IsFull(p)) {
        p->items[p->top] = elem;
        p->top++;
    } else {
        perror("Erro! Pilha cheia!");
        exit(1);
    }
}
