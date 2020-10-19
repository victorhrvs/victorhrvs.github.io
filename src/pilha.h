// Copyright 2020 Victor Henrique do Rêgo Viera de Sousa
#ifndef SRC_PILHA_H_
#define SRC_PILHA_H_

/*! \mainpage Introdução
 *
 * \section intro_sec Trabalho 1 de Métodos de Programação
 * \subsection pilha_sub Pilha de Lista Encadeadas
 * Modo de Uso :
 * @code
 *              Elemento x;
 *              pilha p = createStack();
 *              push(p, x);
 * @endcode
 * \subsection vetor_sub Pilha de Vetor de ItemType
 * Modo de Uso :
 * @code
 *              ItemType v[3];
 *              pilha p;
 *              p = vetorParaPilha(v, 3);
 * @endcode
 * 
 * Também é possível utilizar facilmente valores unitários
 * @code 
 *              ItemType v[] = {1, 2, 3};
 *              pilha p;
 *              p = vetorParaPilha(v, 3); //(Vetor de ItemType, Número de elementos)
 * @endcode
 * 
 */

/*!
* \brief Estrutura do ItemType
*/
typedef int ItemType;

/*!
* \brief Estrutura do Elemento
*/
struct element{
    ItemType item;
};
typedef struct element* Elemento;

/*!
* \brief Estrutura da Pilha
*/
struct Node{
    Elemento elemento;
    struct Node *prox;
};
typedef struct Node* pilha;

/*!
* \brief Retorna verdadeiro se a pilha está vazia e falso caso contrário
* \param pilha
* \return int
*/
int isEmpty(pilha);

/*!
* \brief Retorna verdadeiro se a pilha está cheia e falso caso contrário
* \param pilha
* \return bool
*/
bool isFull(pilha);

/*!
* \brief Cria pilha – retorna pilha
* \return pilha
*/
pilha createStack();

/*!
* \brief Destrói pilha
* \param pilha
* \return int
*/
int destroyStack(pilha);

/*!
* \brief Retorna int tamanho da pilha
* \param pilha
* \return int
*/
int size(pilha);

/*!
* \brief Muda o tamanho da pilha – retorna True se deu certo, False caso contrário
* \param pilha
* \param int
* \return int
*/
int setSize(pilha, int);

/*!
* \brief Retorna elemento do topo da pilha sem modificar a pilha – retorna um elemento
* \param pilha
* \return Elemento
*/
Elemento top(pilha);

/*!
* \brief Coloca elemento no topo da pilha
* \param pilha
* \param Elemento
*/
void push(pilha, Elemento);

/*!
* \brief Retira elemento do topo da pilha – retorna um elemento
* \param pilha
* \param Elemento
*/
Elemento pop(pilha);

/*!
* \brief Retorna o elemento no topo da pilha
* \param pilha
* \return pilha
*/
pilha enesimo_no(pilha p);

/*!
* \brief Converte um vetor para pilha
* \param ItemType
* \return pilha
*/
pilha vetorParaPilha(ItemType *v, int n);

#endif  // SRC_PILHA_H_
