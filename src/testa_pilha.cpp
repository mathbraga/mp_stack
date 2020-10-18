#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/pilha.hpp"

Pilha *stack;

TEST_CASE( "Creating stack", "stack" ) {
    REQUIRE((stack = CreateStack()) != NULL);
}

TEST_CASE( "Destroying stack", "stack" ) {
    DestroyStack(&stack);
    REQUIRE(stack != NULL);
}