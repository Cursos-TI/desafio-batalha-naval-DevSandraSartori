#include <stdio.h>

#define TAM 10      // Tamanho do tabuleiro (10x10)
#define NAVIO 3     // Valor que representa o navio no tabuleiro
#define TAM_NAVIO 3 // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM]; // Matriz do tabuleiro
    int i, j;

    // 1️⃣ Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2️⃣ Define as coordenadas iniciais dos navios
    // Navio horizontal começará na linha 2, coluna 4
    int linhaH = 2;
    int colunaH = 4;

    // Navio vertical começará na linha 5, coluna 7
    int linhaV = 5;
    int colunaV = 7;

    // 3️⃣ Valida se os navios cabem dentro do tabuleiro
    if (colunaH + TAM_NAVIO > TAM || linhaV + TAM_NAVIO > TAM) {
        printf("Erro: coordenadas inválidas. Um dos navios ultrapassa o limite do tabuleiro.\n");
        return 1;
    }

    // 4️⃣ Posiciona o navio horizontal
    for (j = 0; j < TAM_NAVIO; j++) {
        tabuleiro[linhaH][colunaH + j] = NAVIO;
    }

    // 5️⃣ Posiciona o navio vertical (garante que não sobrepõe)
    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaV + i][colunaV] == NAVIO) {
            printf("Erro: sobreposição de navios detectada.\n");
            return 1;
        }
        tabuleiro[linhaV + i][colunaV] = NAVIO;
    }

    // 6️⃣ Exibe o tabuleiro
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}