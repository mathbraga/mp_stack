// Copyright 2020 Matheus Braga
#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/TipoPilha.hpp"
#include "../include/pilha.hpp"

Pilha *stack;

// Teste de criação e remoção da pilha
TEST_CASE("Criando e destruindo pilha", "[stack]") {
    REQUIRE((stack = CreateStack()) != nullptr);
    DestroyStack(&stack);
    REQUIRE(stack == nullptr);
}

SCENARIO("Verificando funcoes IsEmpty, IsFull, Size e SetSize") {
    GIVEN("Uma pilha qualquer vazia") {
        // Cria pilha e verifica se está vazia e cheia
        stack = CreateStack();
        ItemType elemento = 5, aux = 15;
        REQUIRE(IsEmpty(stack) == TRUE);
        REQUIRE_FALSE(IsEmpty(stack) == FALSE);
        REQUIRE(IsFull(stack) == FALSE);
        // Pilha vazia, logo tamanho = 0
        REQUIRE(Size(stack) == 0);
        WHEN("Dar um tamanho pra pilha") {
            // Muda tamanho para 5 e insere 5 elementos
            // SetSize apenas muda caso pilha seja com vetor
            REQUIRE(SetSize(stack, 5) == TRUE);
            Push(stack, ++elemento);
            Push(stack, ++elemento);
            Push(stack, ++elemento);
            Push(stack, ++elemento);
            Push(stack, ++elemento);
            REQUIRE(Size(stack) == 5);
        }
        // Algumas falhas intencionais caso seja dinâmica
        WHEN("Pilha esta cheia") {
            SetSize(stack, 5);
            Push(stack, ++elemento);
            Push(stack, ++elemento);
            Push(stack, ++elemento);
            Push(stack, ++elemento);
            Push(stack, ++elemento);

            // Este teste é apenas para pilha com Vetor
            #if !Pilha_Dinamica
            CHECK(IsFull(stack) == TRUE);
            #endif

            REQUIRE(Size(stack) == 5);
            THEN("Aumentamos o tamanho da pilha") {
                REQUIRE(Top(stack) == elemento);
                REQUIRE(SetSize(stack, 7) == TRUE);
                REQUIRE(IsFull(stack) == FALSE);  // Pilha deixa de estar cheia
                REQUIRE(Top(stack) == elemento);  // Topo continua o mesmo
                Push(stack, aux);
                // Inserimos elemento na nova pilha
                REQUIRE(IsFull(stack) == FALSE);
                // Topo é o último elemento inserido
                REQUIRE(Top(stack) == aux);
                // Inserimos mais um elemento na pilha
                Push(stack, aux+1);

                // Este teste é apenas para pilha com Vetor
                #if !Pilha_Dinamica
                CHECK(IsFull(stack) == TRUE);   // Agora a pilha está cheia
                #endif

                REQUIRE(Top(stack) == aux+1);
                // Retiramos um elemento da pilha
                REQUIRE(Pop(stack) == aux+1);
                REQUIRE(IsFull(stack) == FALSE);  // Pilha deixa de estar cheia
            }
        }
        DestroyStack(&stack);
    }
}

SCENARIO("Verificando funcoes de update da pilha (Push, Top, Pop)") {
    GIVEN("Uma pilha vazia") {
        // Cria pilha vazia e seta tamanho para 5
        stack = CreateStack();
        SetSize(stack, 5);
        ItemType elemento = 1;
        WHEN("Insere um elemento no topo da pilha") {
            Push(stack, elemento);
            THEN("Pilha deixa de estar vazia e tamanho > 0") {
                REQUIRE(IsEmpty(stack) == FALSE);
                REQUIRE(Size(stack) > 0);
            }
            THEN("Topo da pilha passa a ser o ultimo elemento inserido") {
                REQUIRE(Top(stack) == elemento);
                REQUIRE_FALSE(Top(stack) == elemento+2);
            }
        }
        WHEN("Retira um elemento do topo da pilha") {
            // Insere dois elementos na pilha
            Push(stack, 1);
            Push(stack, 2);
            REQUIRE(Top(stack) == 2);
            // Retira um elemento
            REQUIRE(Pop(stack) == 2);
            THEN("Topo passa a ser o elemento anterior ao retirado")
                REQUIRE(Top(stack) == 1);
        }
        DestroyStack(&stack);
    }
}
