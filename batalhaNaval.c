#include <stdio.h>

#define TAM 10          // Tamanho fixo do tabuleiro
#define NAVIO 3         // Tamanho fixo de cada navio
#define AGUA 0          // Representa água
#define NAVIO_VALOR 3   // Representa parte do navio

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // 1️⃣ Inicializa o tabuleiro com água (0)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // -------------------------------
    // 2️⃣ Coordenadas iniciais dos navios
    // Dois navios horizontais/verticais
    int linhaHorizontal = 1, colunaHorizontal = 2; // navio horizontal
    int linhaVertical = 6, colunaVertical = 5;     // navio vertical

    // Dois navios diagonais
    int linhaDiagonal1 = 0, colunaDiagonal1 = 0;   // diagonal principal ↘️
    int linhaDiagonal2 = 7, colunaDiagonal2 = 9;   // diagonal secundária ↙️

    // -------------------------------
    // 3️⃣ Posicionar navio horizontal
    if (colunaHorizontal + NAVIO <= TAM) {
        for (j = 0; j < NAVIO; j++) {
            if (tabuleiro[linhaHorizontal][colunaHorizontal + j] == AGUA)
                tabuleiro[linhaHorizontal][colunaHorizontal + j] = NAVIO_VALOR;
            else {
                printf("Erro: Sobreposição detectada (navio horizontal)\n");
                return 1;
            }
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites.\n");
        return 1;
    }

    // -------------------------------
    // 4️⃣ Posicionar navio vertical
    if (linhaVertical + NAVIO <= TAM) {
        for (i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] == AGUA)
                tabuleiro[linhaVertical + i][colunaVertical] = NAVIO_VALOR;
            else {
                printf("Erro: Sobreposição detectada (navio vertical)\n");
                return 1;
            }
        }
    } else {
        printf("Erro: Navio vertical fora dos limites.\n");
        return 1;
    }

    // -------------------------------
    // 5️⃣ Posicionar navio diagonal ↘️ (linha e coluna aumentam)
    if (linhaDiagonal1 + NAVIO <= TAM && colunaDiagonal1 + NAVIO <= TAM) {
        for (i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] == AGUA)
                tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = NAVIO_VALOR;
            else {
                printf("Erro: Sobreposição detectada (navio diagonal ↘️)\n");
                return 1;
            }
        }
    } else {
        printf("Erro: Navio diagonal ↘️ fora dos limites.\n");
        return 1;
    }

    // -------------------------------
    // 6️⃣ Posicionar navio diagonal ↙️ (linha aumenta, coluna diminui)
    if (linhaDiagonal2 + NAVIO <= TAM && colunaDiagonal2 - (NAVIO - 1) >= 0) {
        for (i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] == AGUA)
                tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = NAVIO_VALOR;
            else {
                printf("Erro: Sobreposição detectada (navio diagonal ↙️)\n");
                return 1;
            }
        }
    } else {
        printf("Erro: Navio diagonal ↙️ fora dos limites.\n");
        return 1;
    }

    // -------------------------------
    // 7️⃣ Exibir o tabuleiro completo
    printf("\n=== TABULEIRO DE BATALHA NAVAL (Nível Aventureiro) ===\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}