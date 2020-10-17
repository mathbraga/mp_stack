#include <stdio.h>
#include <stdlib.h>
#include "TipoPilha.hpp"
#include "pilha.hpp"

Pilha *CreateStack(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    
    if(p == NULL)
        return NULL;

    p->top = 0;

    return p;
}

void DestroyStack(Pilha **p){
    free(*p);
    *p = NULL;

    return;
}