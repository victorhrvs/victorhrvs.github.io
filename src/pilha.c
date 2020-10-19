// Copyright 2020 Victor Henrique do Rêgo Viera de Sousa
#include <stdio.h>
#include <cstdlib>
#include "pilha.h"
#define TRUE 1
#define FALSE 0

int isEmpty(pilha p) {
    // printf("->%p iisEmpty\n",p);
    if (p == NULL) {
            return 0;
    }
    if (p != NULL) {
        if (p->elemento == NULL) {
            return 0;
        }
    }
    // printf("Elemento = %i iisEmpty\n",p->elemento->item);
    return 1;
}

bool isFull(pilha p) {
    p = enesimo_no(p);
    if (p->elemento == NULL) {
        return 0;
    }
    if (p->elemento != NULL) {
        // printf("--->%i",p->elemento->item);
        return 1;
    }
    return -1;
}

pilha createStack() {
    pilha p  = (pilha) malloc(sizeof(Node));
    p->elemento = NULL;
    p->prox = NULL;
    return p;
}

int destroyStack(pilha p) {
    free(p->elemento);
    // printf("No %p\n", p);
    if (p->prox != NULL) {
        destroyStack(p->prox);
        free(p);
        // printf("free %p\n", p);
    }
    return TRUE;
}

int size(pilha p) {
    int n = 0;
    while (p != NULL) {
        n++;
        p = p->prox;
    }
    return n;
}

int setSize(pilha p, int n) {
    pilha aux;
    if (size(p)< n) {
        aux = p;
        while (size(p) < n) {
            //  printf("%d ",size(p));
                if (aux->prox == NULL) {
                    //  printf("No %p\n", p);
                    aux->prox = createStack();
                    //  printf("No %p\n", p);
                }
            aux = aux->prox;
        }
        return TRUE;
    } else { return FALSE;
    }
}

pilha enesimo_no(pilha p) {
    while (p->prox != NULL) {
        p = p->prox;
    }
    return p;
}

Elemento top(pilha p) {
    p = enesimo_no(p);
    return p->elemento;
}

void push(pilha p, Elemento e) {
    pilha aux = p;
    while (p->prox != NULL) {
        aux = p;
        p = p->prox;
    }
    if (isFull(p)){
        p->prox = createStack();
        p = p->prox;
        p->elemento = e;
    } else { 
        p->elemento = e;
        }
}

Elemento pop(pilha p) {
    pilha aux;
    Elemento e;
    while (p->prox != NULL) {
        aux = p;
        p = p->prox;
    }
    e = p->elemento;
    aux->prox = NULL;
    free(p);
    return e;
}

pilha vetorParaPilha(ItemType *v, int n) {
    int i = 0;
    pilha p;
    Elemento e; 
    p = createStack();
    while (i < n) {

        e  = (Elemento) malloc(sizeof(Elemento));
        
        e->item = v[i];
        push(p, e);
        e = NULL;
        i++;
    }
    return p;
}
