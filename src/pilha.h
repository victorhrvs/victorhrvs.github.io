#ifndef PILHA_H
#define PILHA_H

typedef int ItemType; 

//Estrutura do Elemento
struct el{
	ItemType item;
};
typedef struct el* Elemento;

//Estrutura da Pilha
struct plha{
	Elemento elemento;
	struct plha *prox ;
};
typedef struct plha* pilha;


int isEmpty(pilha);
//retorna verdadeiro se a pilha está vazia e falso caso contrário

int isFull(pilha);
//retorna verdadeiro se a pilha está cheia e falso caso contrário

pilha createStack();
//cria pilha – retorna pilha

int destroyStack(pilha);
//destrói pilha

int size(pilha);
//retorna int tamanho da pilha

int setSize(pilha, int);
//muda o tamanho da pilha – retorna True se deu certo, False caso contrário

Elemento top(pilha);
//retorna elemento do topo da pilha sem modificar a pilha – retorna um elemento

void push(pilha, Elemento);
//coloca elemento no topo da pilha

pilha enesimo_no(pilha p);

Elemento pop(pilha);
//retira elemento do topo da pilha – retorna um elemento
/*




*/
#endif