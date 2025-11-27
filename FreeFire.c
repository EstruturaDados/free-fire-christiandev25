#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// --------------------------------------------------------
// Struct que representa cada peça
// Tipo ('I', 'O', 'T', 'L') e ID único
// --------------------------------------------------------
typedef struct {
    char nome;
    int id;
} Peca;

// --------------------------------------------------------
// Constantes do jogo
// --------------------------------------------------------
#define TAM_FILA 5
#define TAM_PILHA 3

// --------------------------------------------------------
// Variáveis globais para gerar IDs únicos
// --------------------------------------------------------
int contadorID = 0;

// --------------------------------------------------------
// Função que gera uma peça aleatória
// --------------------------------------------------------
Peca gerarPeca() {
    char tipos[] = {'I', 'O', 'T', 'L'};
    Peca p;
    p.nome = tipos[rand() % 4];
    p.id = contadorID++;
    return p;
}

// --------------------------------------------------------
// Fila circular de peças futuras
// --------------------------------------------------------
typedef struct {
    Peca dados[TAM_FILA];
    int frente;
    int tras;
} Fila;

// Inicializa a fila
void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = 0;
    for (int i = 0; i < TAM_FILA; i++) {
        f->dados[i] = gerarPeca();
        f->tras = (f->tras + 1) % TAM_FILA;
    }
}

// Remove a peça da frente da fila
Peca dequeue(Fila *f) {
    Peca removida = f->dados[f->frente];
    f->frente = (f->frente + 1) % TAM_FILA;

    // Insere nova peça mantendo a fila cheia
    f->dados[f->tras] = gerarPeca();
    f->tras = (f->tras + 1) % TAM_FILA;

    return removida;
}

// Exibe a fila
void exibirFila(Fila *f) {
    printf("Fila de peças: ");
    int idx = f->frente;

    for (int i = 0; i < TAM_FILA; i++) {
        printf("[%c %d] ", f->dados[idx].nome, f->dados[idx].id);
        idx = (idx + 1) % TAM_FILA;
    }
    printf("\n");
}

// --------------------------------------------------------
// Pilha de peças reservadas
// --------------------------------------------------------
typedef struct {
    Peca dados[TAM_PILHA];
    int topo;
} Pilha;

// Inicializa a pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

// Empilha uma peça
int push(Pilha *p, Peca x) {
    if (p->topo >= TAM_PILHA - 1) {
        printf("\nA pilha está cheia! Não é possível reservar.\n");
        return 0;
    }
    p->dados[++p->topo] = x;
    return 1;
}

// Desempilha uma peça
int pop(Pilha *p, Peca *removida) {
    if (p->topo < 0) {
        printf("\nA pilha está vazia! Não há peças reservadas.\n");
        return 0;
    }
    *removida = p->dados[p->topo--];
    return 1;
}

// Exibe a pilha
void exibirPilha(Pilha *p) {
    printf("Pilha de reserva (Topo -> Base): ");
    for (int i = p->topo; i >= 0; i--) {
        printf("[%c %d] ", p->dados[i].nome, p->dados[i].id);
    }
    if (p->topo < 0)
        printf("(vazia)");
    printf("\n");
}

// --------------------------------------------------------
// Exibe completamente o estado atual
// --------------------------------------------------------
void exibirEstado(Fila *f, Pilha *p) {
    printf("\n===== ESTADO ATUAL =====\n");
    exibirFila(f);
    exibirPilha(p);
    printf("=========================\n");
}

// --------------------------------------------------------
// Função principal
// --------------------------------------------------------
int main() {
    srand(time(NULL));

    Fila fila;
    Pilha pilha;

    inicializarFila(&fila);
    inicializarPilha(&pilha);

    int opcao;
    Peca temp;

    do {
        exibirEstado(&fila, &pilha);

        printf("\nOpções:\n");
        printf("1 - Jogar peça (tirar da fila)\n");
        printf("2 - Reservar peça (fila -> pilha)\n");
        printf("3 - Usar peça reservada (pilha)\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1: // JOGAR PEÇA
                temp = dequeue(&fila);
                printf("\nVocê jogou a peça [%c %d]\n", temp.nome, temp.id);
                break;

            case 2: // RESERVAR PEÇA
                temp = dequeue(&fila);
                if (push(&pilha, temp))
                    printf("\nPeça [%c %d] reservada!\n", temp.nome, temp.id);
                break;

            case 3: // USAR PEÇA DA RESERVA
                if (pop(&pilha, &temp))
                    printf("\nVocê usou a peça reservada [%c %d]\n", temp.nome, temp.id);
                break;

            case 0:
                printf("\nEncerrando o jogo...\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// ---------------------------------------------------------------
// Função para inserir um item na mochila
// Recebe o vetor e seu tamanho atual por referência.
// ---------------------------------------------------------------
void inserirItem(Item mochila[], int *tamanho) {

    if (*tamanho >=*
 Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

int main() {
    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.

    return 0;
}

// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
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
