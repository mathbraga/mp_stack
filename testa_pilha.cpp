#include "pilha.hpp"
#include <gtest/gtest.h>

Pilha *stack;

TEST(NewStack, Stack) { 
    ASSERT_TRUE((stack = CreateStack()) != NULL);
}

TEST(RemoveStack, Stack){
    DestroyStack(&stack);
    ASSERT_TRUE(stack == NULL);
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}