#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/pilha.hpp"

Pilha *stack;

TEST_CASE( "Criando pilha", "[stack]" ) {
    REQUIRE((stack = CreateStack()) != NULL);
}

TEST_CASE( "Destruindo pilha", "[stack]" ) {
    DestroyStack(&stack);
    REQUIRE(stack == NULL);
}

SCENARIO("Verificando funcoes de conteudo da pilha (IsEmpty, IsFull, Size)"){
    GIVEN("Uma pilha vazia"){
        stack = CreateStack();
        REQUIRE(IsEmpty(stack) == TRUE);
        REQUIRE_FALSE(IsEmpty(stack) == FALSE);
        REQUIRE(IsFull(stack) == FALSE);
        REQUIRE(Size(stack) == 0);
        WHEN("Pilha esta cheia"){
            stack->top = SIZE;
            REQUIRE(IsFull(stack) == TRUE);
            REQUIRE(Size(stack) >= SIZE);
        }
        DestroyStack(&stack);
    }
}

SCENARIO("Verificando funcoes de update da pilha (Push, Top, Pop)"){
    GIVEN("Uma pilha vazia"){
        stack = CreateStack();
        ItemType elemento = 5;
        WHEN("Insere um elemento no topo da pilha"){
            Push(stack, elemento);
            THEN("Pilha deixa de estar vazia e tamanho > 0"){
                REQUIRE(IsEmpty(stack) == FALSE);
                REQUIRE(Size(stack) > 0);
            }
            THEN("Topo da pilha passa a ser o ultimo elemento inserido"){
                REQUIRE(Top(stack) == elemento);
                REQUIRE_FALSE(Top(stack) == elemento+2);
            }
        }
        WHEN("Retira um elemento do topo da pilha"){
            Push(stack, 1);
            Push(stack, 2);
            REQUIRE(Size(stack) == 2);
            REQUIRE(Top(stack) == 2);
            REQUIRE(Pop(stack) == 2);
            THEN("Topo passa a ser o elemento anterior ao retirado e seu tamanho diminui em 1 unidade"){
                REQUIRE(Top(stack) == 1);
                REQUIRE(Size(stack) == 1);
            }
        }
        WHEN("Insere ate o limite de espaço da pilha"){
            while(!IsFull(stack)){
                Push(stack, ++elemento);
            }
            THEN("Pilha vai estar cheia")
                REQUIRE(IsFull(stack) == TRUE);
        }
        DestroyStack(&stack);
    }
}

SCENARIO("A pilha estatica com vetor tem tamanho fixo"){
    GIVEN("Uma pilha vazia de tamanho SIZE=100"){
        stack = CreateStack();
        WHEN("Tenta mudar o tamanho da pilha de tamanho fixo"){
            REQUIRE(SetSize(stack, 200) == FALSE);
        }
    }
}