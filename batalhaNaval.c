#include <stdio.h>
#define TAM 10
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\nLegenda: 0 = Água | 3 = Navio | 5 = Área de Habilidade\n\n");
}

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // === 1. Inicializa o tabuleiro com água ===
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // === 2. Posiciona alguns navios (exemplo) ===
    for (j = 2; j < 5; j++) tabuleiro[4][j] = NAVIO;  // navio horizontal
    for (i = 6; i < 9; i++) tabuleiro[i][7] = NAVIO;  // navio vertical

    // === 3. Matrizes das habilidades ===
    int tamH = 5; // tamanho das matrizes de habilidade (5x5)
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // === 4. Criar matriz Cone (em forma de triângulo apontando para baixo) ===
    for (i = 0; i < tamH; i++) {
        for (j = 0; j < tamH; j++) {
            if (j >= tamH/2 - i && j <= tamH/2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // === 5. Criar matriz Cruz ===
    for (i = 0; i < tamH; i++) {
        for (j = 0; j < tamH; j++) {
            if (i == tamH/2 || j == tamH/2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // === 6. Criar matriz Octaedro (formato de losango) ===
    for (i = 0; i < tamH; i++) {
        for (j = 0; j < tamH; j++) {
            if (abs(i - tamH/2) + abs(j - tamH/2) <= tamH/2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // === 7. Aplicar habilidades no tabuleiro ===
    // Pontos de origem (centro das habilidades)
    int origemCone[2] = {2, 2};
    int origemCruz[2] = {6, 3};
    int origemOcta[2] = {5, 8};

    // Função de sobreposição
    for (int tipo = 0; tipo < 3; tipo++) {
        int (*habilidade)[5];  // ponteiro para matriz de habilidade
        int origemLinha, origemColuna;

        if (tipo == 0) {
            habilidade = cone;
            origemLinha = origemCone[0];
            origemColuna = origemCone[1];
            printf("Aplicando habilidade: CONE\n");
        } else if (tipo == 1) {
            habilidade = cruz;
            origemLinha = origemCruz[0];
            origemColuna = origemCruz[1];
            printf("Aplicando habilidade: CRUZ\n");
        } else {
            habilidade = octaedro;
            origemLinha = origemOcta[0];
            origemColuna = origemOcta[1];
            printf("Aplicando habilidade: OCTAEDRO\n");
        }

        // Sobreposição da habilidade no tabuleiro
        for (i = 0; i < tamH; i++) {
            for (j = 0; j < tamH; j++) {
                if (habilidade[i][j] == 1) {
                    int linha = origemLinha + i - tamH/2;
                    int coluna = origemColuna + j - tamH/2;

                    // Validação dos limites do tabuleiro
                    if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                        if (tabuleiro[linha][coluna] == AGUA)
                            tabuleiro[linha][coluna] = HABILIDADE;
                    }
                }
            }
        }
        imprimirTabuleiro(tabuleiro);
    }

    return 0;
}
