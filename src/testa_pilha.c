// calc_test.cpp
#include "gtest/gtest.h"
#include "pilha.h"

TEST(CalcTest, Add) {
    ASSERT_EQ(2, add(1, 1));
    ASSERT_EQ(5, add(3, 2));
    ASSERT_EQ(10, add(7, 3));
}

TEST(CalcTest, Sub) {
    ASSERT_EQ(3, sub(5, 2));
    ASSERT_EQ(-10, sub(5, 15));
}

TEST(TestePilha, IsEmpty) {
    Pilha pil  = (Pilha) malloc(sizeof(pilha));
    //printf("%p\n",pil->elemento);
    
    //printf("%p\n",pil->elemento);
    
    //TESTE QUANDO A PILHA ESTA VAZIA
    ASSERT_EQ(0, isEmpty(NULL));
    ASSERT_EQ(0, isEmpty(pil));

    pil->elemento  = (Elemento) malloc(sizeof(Elemento));
    pil->elemento->item = 42;

    //QUANDO PILHA POSSUE PELO MENOS UM ELEMENTO
    ASSERT_EQ(1, isEmpty(pil));

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}