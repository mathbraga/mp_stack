#include <stdio.h>
#include <stdlib.h>
#include "TipoPilha.hpp"

typedef struct {
    ItemType items[MAXSIZE];
    int top;
} Pilha;

Pilha *CreateStack();