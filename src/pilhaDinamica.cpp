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

    p->top = NULL;

    return p;
}

// Destroi pilha
void DestroyStack(Pilha **p) {
    while (Size(*p) != 0)
        Pop(*p);

    free(*p);
    *p = nullptr;
}

// Verifica se pilha está vazia
int IsEmpty(Pilha *p) {
    if ((p->top) == NULL)
        return TRUE;
    else
        return FALSE;
}

// Verifica se pilha está cheia
int IsFull(Pilha *p) {
    // assumi que para implementação com pilha dinâmica,
    // a pilha nunca estará cheia, a não ser que houve algum
    // problema na alocação de memória, problema não relacionado
    // com esta função
    return FALSE;
}

// Emprega um tamanho para pilha com vetor
int SetSize(Pilha *p, int new_size) {
    // assumi que para a implementação dinâmica, esta função é desnecessária
    // pois a ideia de se ter uma pilha dinâmica é que ela expande a medida
    // que mais elementos são inseridos nela
    return TRUE;
}

// Retorna o tamanho da pilha
int Size(Pilha *p) {
    Item *aux = p->top;
    int tam = 0;
    while (aux != NULL) {
        tam++;
        aux = aux->next;
    }
    return tam;
}

// Retorna o elemento do topo da pilha
ItemType Top(Pilha *p) {
    return p->top->elemento;
}

// Retira o elemento do topo da pilha
ItemType Pop(Pilha *p) {
    if (IsEmpty(p)) {
        perror("Erro! Pilha vazia!");
        exit(1);
    }
    ItemType ret;
    Item *aux;
    ret = p->top->elemento;
    aux = p->top;
    p->top = aux->next;
    free(aux);

    return ret;
}

// Insere um elemento no topo da pilha
void Push(Pilha *p, ItemType elem) {
    Item *novo = reinterpret_cast<Item*>(malloc(sizeof(Item)));
    novo->elemento = elem;
    novo->next = p->top;
    p->top = novo;
}
