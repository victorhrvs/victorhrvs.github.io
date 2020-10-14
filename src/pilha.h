#ifndef PILHA_H
#define PILHA_H

int add(int , int );
int sub(int , int );

typedef int ItemType; 

//Estrutura do Elemento
struct el{
	ItemType item;
};
typedef struct el* Elemento;


struct pilha{
	Elemento elemento = NULL;
	struct pilha *prox ;
};
typedef struct pilha* Pilha;


int isEmpty(Pilha);
//retorna verdadeiro se a pilha está vazia e falso caso contrário

/*
void push(pilha, elemento);
//coloca elemento no topo da pilha

elemento pop(pilha);
//retira elemento do topo da pilha – retorna um elemento

elemento top(pilha);
//retorna elemento do topo da pilha sem modificar a pilha – retorna um elemento

int size(pilha);
//retorna int tamanho da pilha

bool setSize(pilha, int);
//muda o tamanho da pilha – retorna True se deu certo, False caso contrário

bool isFull(pilha);
//retorna verdadeiro se a pilha está cheia e falso caso contrário

bool isEmpty(pilha);
//retorna verdadeiro se a pilha está vazia e falso caso contrário

pilha createStack();
//cria pilha – retorna pilha

void destroyStack(pilha);
//destrói pilha
*/
#endif