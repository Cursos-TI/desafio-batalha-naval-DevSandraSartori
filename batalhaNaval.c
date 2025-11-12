#include <stdio.h>

#define TAM 10          // Tamanho fixo do tabuleiro
#define NAVIO 3         // Tamanho fixo de cada navio
#define AGUA 0          // Representa água
#define NAVIO_VALOR 3   // Representa parte do navio
#define HABILIDADE 5    // Representa a área afetada por habilidades
#define HAB_TAM 5       // Tamanho das matrizes de habilidades (5x5)

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para imprimir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO DE BATALHA NAVAL (Nível Mestre) ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == AGUA) printf("~ ");     // Água
            else if (tabuleiro[i][j] == NAVIO_VALOR) printf("🚢 ");
            else if (tabuleiro[i][j] == HABILIDADE) printf("🔥 ");
            else printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função genérica para sobrepor uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[HAB_TAM][HAB_TAM], int origemLinha, int origemColuna) {
    int offset = HAB_TAM / 2; // deslocamento para centralizar

    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha + (i - offset);
                int coluna = origemColuna + (j - offset);

                // verifica se a posição está dentro dos limites do tabuleiro
                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                    // Marca a área afetada pela habilidade com o valor 5
                    // sem sobrescrever navios
                    if (tabuleiro[linha][coluna] == AGUA)
                        tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

// Cria a matriz da habilidade em forma de cone (ponta para baixo)
void criarCone(int cone[HAB_TAM][HAB_TAM]) {
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (j >= HAB_TAM/2 - i && j <= HAB_TAM/2 + i && i < HAB_TAM) 
                cone[i][j] = 1;
            else 
                cone[i][j] = 0;
        }
    }
}

// Cria a matriz da habilidade em forma de cruz
void criarCruz(int cruz[HAB_TAM][HAB_TAM]) {
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (i == HAB_TAM/2 || j == HAB_TAM/2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// Cria a matriz da habilidade em forma de octaedro (losango)
void criarOctaedro(int octaedro[HAB_TAM][HAB_TAM]) {
    int centro = HAB_TAM / 2;
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // 🛳️ Posiciona alguns navios fixos
    for (int j = 3; j < 3 + NAVIO; j++) tabuleiro[2][j] = NAVIO_VALOR; // horizontal
    for (int i = 6; i < 6 + NAVIO; i++) tabuleiro[i][5] = NAVIO_VALOR; // vertical

    // ✨ Cria as matrizes das habilidades
    int cone[HAB_TAM][HAB_TAM];
    int cruz[HAB_TAM][HAB_TAM];
    int octaedro[HAB_TAM][HAB_TAM];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // 🎯 Define as posições das habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 1, 2);       // Cone com origem no topo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 8, 8);   // Octaedro no canto inferior direito

    // 🔥 Exibe o tabuleiro com áreas de efeito
    exibirTabuleiro(tabuleiro);

    return 0;
}