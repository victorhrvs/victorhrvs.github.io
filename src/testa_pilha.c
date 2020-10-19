// Copyright 2020 Victor Henrique do Rêgo Viera de Sousa
#include <gtest/gtest.h>
#include "pilha.h"
#define TRUE 1
#define FALSE 0

// TESTES DE PILHA VAZIA
TEST(TestePilha, IsEmpty) {
    pilha pil  = (pilha) malloc(sizeof(Node));
    // printf("%p\n",pil->elemento);
    // printf("%p\n",pil->elemento);

    // TESTE QUANDO A PILHA ESTA VAZIA
    ASSERT_EQ(0, isEmpty(NULL));
    ASSERT_EQ(0, isEmpty(pil));

    pil->elemento  = (Elemento) malloc(sizeof(Elemento));
    pil->elemento->item = 42;

    // QUANDO PILHA POSSUE PELO MENOS UM ELEMENTO
    ASSERT_EQ(1, isEmpty(pil));

    free(pil->elemento);
    free(pil);
}


// TESTES PARA PILHA CHEIA
TEST(IsFull, False) {
    pilha p  = (pilha) malloc(sizeof(Node));
    p->elemento = NULL;
    // printf("---=>%i", p->elemento);
    ASSERT_EQ(0, isFull(p));
    free(p);
}

TEST(IsFull, True) {
    pilha pil  = (pilha) malloc(sizeof(Node));
    pil->elemento  = (Elemento) malloc(sizeof(Elemento));
    // pil->elemento->item = 42;

    ASSERT_EQ(TRUE, isFull(pil));

    free(pil->elemento);
    free(pil);
}

TEST(CreateStack, RetornaPilha) {
    pilha pil;
    pil = createStack();

    // Verifica se a pilha tem espaço para adicionar um elemento
    ASSERT_EQ(0, isFull(pil));
    free(pil);
}

// TESTES DE DESTRUIÇÃO DE PILHA
TEST(DestroyStack, UnicoNo) {
    pilha pil = createStack();
    ASSERT_EQ(TRUE, destroyStack(pil));
}

TEST(DestroyStack, N_No) {
    pilha p1 = createStack();
    pilha p2 = createStack();
    pilha p3 = createStack();
    p1->prox = p2;
    p2->prox = p3;
    ASSERT_EQ(TRUE, destroyStack(p1));
}

TEST(Size, N_SIZE) {
    pilha p1 = createStack();
    pilha p2 = createStack();
    pilha p3 = createStack();
    p1->prox = p2;
    p2->prox = p3;

    ASSERT_EQ(3, size(p1));
}

// AUMENTAR O TAMANHO DA PILHA
TEST(SetSize, True) {
    pilha p1 = createStack();
    pilha p2 = createStack();
    pilha p3 = createStack();
    p1->prox = p2;
    p2->prox = p3;
    ASSERT_EQ(TRUE, setSize(p1, 10000));
    ASSERT_EQ(10000, size(p1));
    ASSERT_EQ(TRUE, destroyStack(p1));
}

TEST(SetSize, False) {
    // Se o tamanho escolhido for menor que o tamanho atual da pilha,
    // o tamanho não será modificado para que não ocorra a perda de
    // informação no final da pilha
    pilha p1 = createStack();
    pilha p2 = createStack();
    pilha p3 = createStack();
    p1->prox = p2;
    p2->prox = p3;
    ASSERT_EQ(FALSE, setSize(p1, 2));
    ASSERT_EQ(3, size(p1));
}

TEST(TOP, ELEMENTO) {
    pilha p1 = createStack();
    pilha p2 = createStack();
    pilha p3 = createStack();
    p1->prox = p2;
    p2->prox = p3;
    p3->elemento = (Elemento) malloc(sizeof(Elemento));
    ASSERT_EQ(p3->elemento, top(p1));
    // printf("%p = %p", p1->elemento, top(p1));
    ASSERT_EQ(TRUE, destroyStack(p1));
}

TEST(PUSH, ELEMENTO) {
    pilha p = createStack();
    Elemento x;

    push(p, x);
    ASSERT_EQ(x, p->elemento);
    //printf("\n%p = %i\n", x, p->elemento->item);

    push(p, x);
    //printf("\n%p == %i\n", x, p->prox->elemento->item);
    ASSERT_EQ(x, p->prox->elemento);

    push(p, x);
    //printf("\n%p === %i\n", x, p->prox->prox->elemento->item);
    ASSERT_EQ(x, p->prox->prox->elemento);


}

TEST(POP, ELEMENTO) {
    Elemento x;
    pilha p1 = createStack();
    pilha p2 = createStack();
    pilha p3 = createStack();
    p1->prox = p2;
    p2->prox = p3;
    p3->elemento = x;
    ASSERT_EQ(x, pop(p1));
    ASSERT_EQ(NULL, p2->prox);
}

TEST(VETOR, PILHA) {
    ItemType v[3];
    //Também testado com valores unitários
    //ItemType v[] = {1, 2, 3};
    pilha p;

    p = vetorParaPilha(v, 3);
    ASSERT_EQ(v[0], p->elemento->item);
    p = p->prox;
    ASSERT_EQ(v[1], p->elemento->item);
    p = p->prox;
    ASSERT_EQ(v[2], p->elemento->item);
    p = p->prox;
    ASSERT_EQ(NULL, p);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
