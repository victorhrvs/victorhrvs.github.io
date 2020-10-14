#include <cstddef>
#include <stdio.h>

#include "pilha.h"

int add(int op1, int op2) {
    return op1 + op2;
}

int sub(int op1, int op2) {
    return op1 - op2;
}

int isEmpty(Pilha p){
    //printf("->%p iisEmpty\n",p);
    if(p == NULL){
            return 0;
    }
    if(p != NULL){
        if(p->elemento == NULL){
            return 0;
        }
    }
    //printf("Elemento = %i iisEmpty\n",p->elemento->item);
    return 1;
}
