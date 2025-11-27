#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------------------------------------------------------------
// STRUCTS
// --------------------------------------------------------------

// Estrutura de uma sala da mansão (árvore binária simples)
typedef struct Sala {
    char nome[50];
    char pista[100];    // pode estar vazia
    struct Sala *esq;
    struct Sala *dir;
} Sala;

// Nó da BST de pistas
typedef struct PistaNode {
    char conteudo[100];
    struct PistaNode *esq;
    struct PistaNode *dir;
} PistaNode;

// --------------------------------------------------------------
// FUNÇÃO: criarSala
// cria dinamicamente uma sala com nome e pista (opcional)
// --------------------------------------------------------------
Sala* criarSala(char nome[], char pista[]) {
    Sala *s = (Sala*) malloc(sizeof(Sala));
    strcpy(s->nome, nome);
    strcpy(s->pista, pista);
    s->esq = NULL;
    s->dir = NULL;
    return s;
}

// --------------------------------------------------------------
// FUNÇÃO: inserirPista
// insere recursivamente uma nova pista na BST em ordem alfabética
// --------------------------------------------------------------
PistaNode* inserirPista(PistaNode *raiz, char conteudo[]) {

    if (raiz == NULL) {
        PistaNode *novo = (PistaNode *) malloc(sizeof(PistaNode));
        strcpy(novo->conteudo, conteudo);
        novo->esq = novo->dir = NULL;

// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
