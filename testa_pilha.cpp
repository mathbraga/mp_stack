#include "pilha.cpp"
#include <gtest/gtest.h>

Pilha *stack;

TEST(StackTest, ValidStack) { 
    ASSERT_TRUE((stack = CreateStack()) != NULL);
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}