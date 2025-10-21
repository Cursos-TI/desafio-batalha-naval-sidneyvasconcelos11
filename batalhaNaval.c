#include <stdio.h>

#define tamanhoTabuleiro 10
#define tamanhoNavio 3

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro] = {0}; // Legenda para o Tabuleiro:  0 = água, 3 = navio

     // Coordenadas dos navios
    int linhaNavioHorizontal = 2; // linha inicial do navio na horizontal
    int colunaNavioHorizontal = 4; // coluna inicial do navio na horizontal
    
    int linhaNavioVertical = 5; // linha inicial do navio na vertical
    int colunaNavioVertical = 7; // coluna inicial do navio na vertical

    // POSIÇÃO DO NAVIO NA HORIZONTAL
    if (colunaNavioHorizontal + tamanhoNavio <= tamanhoTabuleiro) {
        for (int i = 0; i < tamanhoNavio; i++) {
            // Marca a posição do navio com 3
            tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
        }
    } else {
        printf("Navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // POSIÇÃO DO NAVIO NA VERTICAL
    if (linhaNavioVertical + tamanhoNavio <= tamanhoTabuleiro) {
        for (int i = 0; i < tamanhoNavio; i++) {
            // verificar antes se já há outro navio no local.
            if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] == 3) {
                printf("Erro: navio vertical se sobrepõe ao navio horizontal.\n");
                return 1;
            }
            tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
        }
    } else {
        printf("Navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // EXIBIÇÃO DO TABULEIRO
    printf("===============================\n");
    printf("=== TABULEIRO BATALHA NAVAL ===\n");
    printf("===============================\n\n");
    for (int linha = 0; linha < tamanhoTabuleiro; linha++) {
        for (int coluna = 0; coluna < tamanhoTabuleiro; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Navio\n");
    printf("===============================\n\n");

    return 0;
}
