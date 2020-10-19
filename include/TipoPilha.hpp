/* 
   O tipo genérico ItemType deve ser definido aqui.
   Para trocar o tipo de ItemType, basta trocar o tipo
   após a instrução typedef. O valor default é inteiro
   então "typedef int ItemType;".

   O tipo de implementação da pilha é definida pela
   variável Pilha_Dinamica. Se Pilha_Dinamica=0, o 
   tipo de pilha será com Vetor, caso contrário, 
   será com Lista encadeada.
*/

#ifndef PILHA_INCLUDE_TIPOPILHA_H_
#define PILHA_INCLUDE_TIPOPILHA_H_

// Definir tipo de pilha
#define Pilha_Dinamica 0 // 0-Vetor | 1-Lista

typedef int ItemType; // Definir tipo do ItemType

// Bloco de controle condicional para qual tipo de pilha vai ser usada
#if !Pilha_Dinamica

// Pilha com vetor
typedef struct{
    ItemType *items;
    int tamanho;
    int top;
}Pilha;
// fim

#else
// Pilha dinâmica
typedef struct ItemInfo{
    ItemType elemento;
    ItemInfo *next;
}Item;

typedef struct{
    Item *top;
}Pilha;
// fim
#endif

#ifndef TRUE
#define TRUE (1 == 1)
#endif

#ifndef FALSE
#define FALSE (0 == 1)
#endif

#endif  // PILHA_INCLUDE_TIPOPILHA_H_