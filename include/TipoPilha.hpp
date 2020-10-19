/* O tipo genérico ItemType deve ser definido aqui.

   O tipo de implementação da pilha ativa é a que não
   está comentada.

   Para trocar o tipo de pilha basta retirar o comentado
   do tipo desejado que está demarcado entre os comentários
   de tipo "Pilha com vetor" ou "Pilha dinâmica" até o comentário
   "fim" e comentar a definição do outro tipo.
*/

#ifndef PILHA_INCLUDE_TIPOPILHA_H_
#define PILHA_INCLUDE_TIPOPILHA_H_

typedef int ItemType; //definir tipo do ItemType

// Pilha com vetor
// typedef struct{
//     ItemType *items;
//     int tamanho;
//     int top;
// }Pilha;
// fim

// Pilha dinâmica
typedef struct ItemInfo{
    ItemType elemento;
    ItemInfo *next;
}Item;

typedef struct{
    Item *top;
}Pilha;
// fim

#ifndef TRUE
#define TRUE (1 == 1)
#endif

#ifndef FALSE
#define FALSE (0 == 1)
#endif

#endif  // PILHA_INCLUDE_TIPOPILHA_H_