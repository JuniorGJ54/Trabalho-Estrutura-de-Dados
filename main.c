#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define VALORES 100

int comparacoes = 0;

struct Node {
    int valor;
    struct Node* esquerda;
    struct Node* direita;
};

struct Node* novo_no(int valor) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->valor = valor;
    node->esquerda = NULL;
    node->direita = NULL;
    return node;
}

struct Node* inserir(struct Node* node, int valor) {
    if (node == NULL) {
        return novo_no(valor);
    }
    if (valor < node->valor) {
        node->esquerda = inserir(node->esquerda, valor);
    } else if (valor > node->valor) {
        node->direita = inserir(node->direita, valor);
    }
    return node;
}

void preOrderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->valor);
    preOrderTraversal(node->esquerda);
    preOrderTraversal(node->direita);
}

void exibir_arvore_pre_order(struct Node* node, int nivel) {
    if (node != NULL) {
        for (int i = 0; i < nivel; i++) {
            printf("   "); 
        }
        printf("%d\n", node->valor); 

        exibir_arvore_pre_order(node->esquerda, nivel + 1); 
        exibir_arvore_pre_order(node->direita, nivel + 1);  
    }
}

void bubble_sort(int vetor[], int n) {
    int k, j, aux;
    for (k = n - 1; k > 0; k--) {
        for (j = 0; j < k; j++) {
            comparacoes++;
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main() {
    int mod;
    int vetor[VALORES];
    clock_t inicio, fim;
    double tempo_execucao;
    struct Node* raiz = NULL; 
    
    printf("------------------------------------------------------------\n");
    printf("Davi Soares Braz da Silva \n Matricula: 202306034051 \n\n");
    printf("Gabriel Rodrigues Pereira Barbosa \n Matricula: 202303493959 \n\n");
    printf("Genival dos Santos Júnior \n Matricula: 202308418645 \n\n");
    
    mod = (1 + 9 + 5) % 3;
    
    printf("Soma dos Digitos = 15 / Módulo 3 da soma = %d \n", mod);
    printf("SELECIONADOS: Bubble Sort e Árvore em Pre-Ordem\n\n");
    
    printf("Vetor Desordenado\n");
    srand(time(NULL));
    
    for (int i = 0; i < VALORES; i++) {
        int num;
        bool repetido;
        do {
            repetido = false;
            num = rand() % 1000 + 1;

            for (int j = 0; j < i; j++) {
                if (vetor[j] == num) {
                    repetido = true;
                    break;
                }
            }
        } while (repetido);

        vetor[i] = num;
    }

    for (int z = 0; z < VALORES; z++) { 
        printf("%d ", vetor[z]); 
    }
    
    for (int i = 0; i < VALORES; i++) {
        raiz = inserir(raiz, vetor[i]);
    }
    
    printf("\n\nÁrvore Binária em Pré-Ordem:\n");
    preOrderTraversal(raiz); 
    printf("\n"); 
    printf("\nÁrvore Binária Identada:\n");
    exibir_arvore_pre_order(raiz, 0); 
    
    inicio = clock();
    bubble_sort(vetor, VALORES);
    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;
    
    printf("\nVetor Ordenado com Bubble Sort\n");
    for (int z = 0; z < VALORES; z++) { 
        printf("%d ", vetor[z]); 
    }
    
    printf("\n\nNúmero de comparações no Bubble Sort: %d", comparacoes);
    printf("\nTempo de execução do Bubble Sort: %.5f milissegundos\n", tempo_execucao);
    
    return 0;
}
