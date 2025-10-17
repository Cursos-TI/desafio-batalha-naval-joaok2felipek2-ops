#include <stdio.h>

#define TAM 10  // tamanho do tabuleiro 10x10
#define NAVIO 3 // valor que representa as partes do navio
#define AGUA 0  // valor que representa água

int main() {
    int tabuleiro[TAM][TAM]; // matriz 10x10 do tabuleiro
    int i, j;

    // === 1. Inicializa o tabuleiro com água (0) ===
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // === 2. Declaração dos navios ===
    int navio_horizontal[3] = {NAVIO, NAVIO, NAVIO};
    int navio_vertical[3] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais (definidas no código)
    int linha_h = 2, coluna_h = 3; // navio horizontal começa na posição (2,3)
    int linha_v = 5, coluna_v = 6; // navio vertical começa na posição (5,6)

    // === 3. Validação dos limites ===
    if (coluna_h + 3 > TAM) {
        printf("Erro: navio horizontal fora do limite do tabuleiro!\n");
        return 1;
    }

    if (linha_v + 3 > TAM) {
        printf("Erro: navio vertical fora do limite do tabuleiro!\n");
        return 1;
    }

    // === 4. Posiciona o navio horizontal ===
    for (i = 0; i < 3; i++) {
        // Garante que não sobrepõe outro navio
        if (tabuleiro[linha_h][coluna_h + i] == NAVIO) {
            printf("Erro: sobreposição de navios!\n");
            return 1;
        }
        tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
    }

    // === 5. Posiciona o navio vertical ===
    for (i = 0; i < 3; i++) {
        // Garante que não sobrepõe outro navio
        if (tabuleiro[linha_v + i][coluna_v] == NAVIO) {
            printf("Erro: sobreposição de navios!\n");
            return 1;
        }
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

    // === 6. Exibe o tabuleiro ===
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Navio\n");

    return 0;
}
