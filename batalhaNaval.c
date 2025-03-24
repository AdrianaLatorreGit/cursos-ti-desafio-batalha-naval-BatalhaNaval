// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#include <stdio.h>
#include <stdbool.h>

    // Nível Novato - Posicionamento dos Navios
    
    #define TAM_TABULEIRO 5
    #define TAM_NAVIO 3
    #define AGUA 0
    #define NAVIO 1
    
    void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
    bool posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna);
    bool posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna);
    void exibirCoordenadasNavios(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
    void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
    
    int main() {
        // Declaração do tabuleiro 5x5
        int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
        
        // Inicializa o tabuleiro com água (0)
        inicializarTabuleiro(tabuleiro);
        
        printf("Batalha Naval (Tabuleiro 5x5)\n");
        
        // Posiciona o navio horizontal (coordenadas fixas)
        printf("\nPosicionando navio horizontal...\n");
        if (posicionarNavioHorizontal(tabuleiro, 1, 1)) {
            printf("Navio horizontal posicionado com sucesso!\n");
        } else {
            printf("Erro ao posicionar navio horizontal!\n");
            return 1;
        }
        
        // Posiciona o navio vertical (coordenadas fixas)
        printf("\nPosicionando navio vertical...\n");
        if (posicionarNavioVertical(tabuleiro, 2, 3)) {
            printf("Navio vertical posicionado com sucesso!\n");
        } else {
            printf("Erro ao posicionar navio vertical!\n");
            return 1;
        }
        
        // Exibe as coordenadas dos navios
        printf("\nCoordenadas dos navios:\n");
        exibirCoordenadasNavios(tabuleiro);
        
        // Exibe o tabuleiro completo
        printf("\nTabuleiro completo:\n");
        exibirTabuleiro(tabuleiro);
        
        return 0;
    }
    
    // Inicializa todas as posições do tabuleiro com água (0)
    void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
        for (int i = 0; i < TAM_TABULEIRO; i++) {
            for (int j = 0; j < TAM_TABULEIRO; j++) {
                tabuleiro[i][j] = AGUA;
            }
        }
    }
    
    // Posiciona um navio horizontalmente
    bool posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
        // Verifica se o navio cabe no tabuleiro
        if (linha < 0 || linha >= TAM_TABULEIRO || coluna < 0 || coluna + TAM_NAVIO > TAM_TABULEIRO) {
            return false;
        }
        
        // Posiciona o navio
        for (int j = coluna; j < coluna + TAM_NAVIO; j++) {
            tabuleiro[linha][j] = NAVIO;
        }
        
        return true;
    }
    
    // Posiciona um navio verticalmente
    bool posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
        // Verifica se o navio cabe no tabuleiro
        if (linha < 0 || linha + TAM_NAVIO > TAM_TABULEIRO || coluna < 0 || coluna >= TAM_TABULEIRO) {
            return false;
        }
        
        // Posiciona o navio
        for (int i = linha; i < linha + TAM_NAVIO; i++) {
            tabuleiro[i][coluna] = NAVIO;
        }
        
        return true;
    }
    
    // Exibe as coordenadas de todas as partes dos navios
    void exibirCoordenadasNavios(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
        printf("Partes dos navios:\n");
        for (int i = 0; i < TAM_TABULEIRO; i++) {
            for (int j = 0; j < TAM_TABULEIRO; j++) {
                if (tabuleiro[i][j] == NAVIO) {
                    printf("Navio na posicao [%d][%d]\n", i, j);
                }
            }
        }
    }
    
    // Exibe o tabuleiro no console
    void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
        printf("   ");
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", j); // Cabeçalho das colunas
        }
        printf("\n");
        
        for (int i = 0; i < TAM_TABULEIRO; i++) {
            printf("%d: ", i); // Número da linha
            for (int j = 0; j < TAM_TABULEIRO; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal

#include <stdio.h>
#include <stdbool.h>

    #define TAM_TABULEIRO 10
    #define TAM_NAVIO 3
    #define AGUA 0
    #define NAVIO 3

    void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
    bool posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcao);
    void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
    bool posicaoValida(int linha, int coluna);
    bool verificarDisponibilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcao);

    int main() {
        // Inicializa o tabuleiro 10x10
        int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
        inicializarTabuleiro(tabuleiro);
        
        printf("=== BATALHA NAVAL ===\n");
        printf("Tabuleiro 10x10 com navios horizontais, verticais e diagonais\n\n");
   
        // 1 - Navio horizontal
        if (posicionarNavio(tabuleiro, 2, 2, 0)) {
            printf("Navio horizontal posicionado em (2,2)-(2,4)\n");
        } else {
            printf("Erro ao posicionar navio horizontal!\n");
            return 1;
        }
        
        // 2 - Navio vertical
        if (posicionarNavio(tabuleiro, 5, 7, 1)) {
            printf("Navio vertical posicionado em (5,7)-(7,7)\n");
        } else {
            printf("Erro ao posicionar navio vertical!\n");
            return 1;
        }
        
        // 3 - Navio diagonal decrescente (\)
        if (posicionarNavio(tabuleiro, 1, 1, 2)) {
            printf("Navio diagonal (\\) posicionado em (1,1)-(3,3)\n");
        } else {
            printf("Erro ao posicionar navio diagonal decrescente!\n");
            return 1;
        }
        
        // 4 - Navio diagonal crescente (/)
        if (posicionarNavio(tabuleiro, 3, 7, 3)) {
            printf("Navio diagonal (/) posicionado em (3,7)-(5,5)\n");
        } else {
            printf("Erro ao posicionar navio diagonal crescente!\n");
            return 1;
        }
        
        // Exibe o tabuleiro completo
        printf("\nTabuleiro completo:\n");
        exibirTabuleiro(tabuleiro);
        
        return 0;
    }

    // Inicializa o tabuleiro com água (0)
    void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
        for (int i = 0; i < TAM_TABULEIRO; i++) {
            for (int j = 0; j < TAM_TABULEIRO; j++) {
                tabuleiro[i][j] = AGUA;
            }
        }
    }

    // Função unificada para posicionar navios
    bool posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcao) {
        // Verifica se a posição é válida
        if (!verificarDisponibilidade(tabuleiro, linha, coluna, direcao)) {
            return false;
        }
        
        // Posiciona o navio de acordo com a direção
        switch (direcao) {
            case 0: // Horizontal →
                for (int j = coluna; j < coluna + TAM_NAVIO; j++) {
                    tabuleiro[linha][j] = NAVIO;
                }
                break;
                
            case 1: // Vertical ↓
                for (int i = linha; i < linha + TAM_NAVIO; i++) {
                    tabuleiro[i][coluna] = NAVIO;
                }
                break;
                
            case 2: // Diagonal decrescente \ 
                for (int i = 0; i < TAM_NAVIO; i++) {
                    tabuleiro[linha + i][coluna + i] = NAVIO;
                }
                break;
                
            case 3: // Diagonal crescente /
                for (int i = 0; i < TAM_NAVIO; i++) {
                    tabuleiro[linha + i][coluna - i] = NAVIO;
                }
                break;
                
            default:
                return false;
        }
        
        return true;
    }

    // Verifica se uma posição está dentro do tabuleiro
    bool posicaoValida(int linha, int coluna) {
        return linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO;
    }

    // Verifica se as posições para o navio estão disponíveis
    bool verificarDisponibilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcao) {
        switch (direcao) {
            case 0: // Horizontal
                if (!posicaoValida(linha, coluna) || !posicaoValida(linha, coluna + TAM_NAVIO - 1)) {
                    return false;
                }
                for (int j = coluna; j < coluna + TAM_NAVIO; j++) {
                    if (tabuleiro[linha][j] != AGUA) return false;
                }
                break;
                
            case 1: // Vertical
                if (!posicaoValida(linha, coluna) || !posicaoValida(linha + TAM_NAVIO - 1, coluna)) {
                    return false;
                }
                for (int i = linha; i < linha + TAM_NAVIO; i++) {
                    if (tabuleiro[i][coluna] != AGUA) return false;
                }
                break;
                
            case 2: // Diagonal decrescente
                if (!posicaoValida(linha, coluna) || !posicaoValida(linha + TAM_NAVIO - 1, coluna + TAM_NAVIO - 1)) {
                    return false;
                }
                for (int i = 0; i < TAM_NAVIO; i++) {
                    if (tabuleiro[linha + i][coluna + i] != AGUA) return false;
                }
                break;
                
            case 3: // Diagonal crescente
                if (!posicaoValida(linha, coluna) || !posicaoValida(linha + TAM_NAVIO - 1, coluna - TAM_NAVIO + 1)) {
                    return false;
                }
                for (int i = 0; i < TAM_NAVIO; i++) {
                    if (tabuleiro[linha + i][coluna - i] != AGUA) return false;
                }
                break;
                
            default:
                return false;
        }
        return true;
    }

    // Exibe o tabuleiro formatado
    void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
        // Cabeçalho das colunas
        printf("   ");
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%2d ", j);
        }
        printf("\n");
        
        // Linhas do tabuleiro
        for (int i = 0; i < TAM_TABULEIRO; i++) {
            printf("%2d ", i); // Número da linha
            for (int j = 0; j < TAM_TABULEIRO; j++) {
                printf("%2d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    
    // Constantes do jogo
    #define TAM_TABULEIRO 10
    #define TAM_HABILIDADE 5
    #define AGUA 0
    #define NAVIO 3
    #define HABILIDADE 1  // Alterado para 1 conforme sugestão
    
    // Protótipos de funções
    void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
    void posicionarNavios(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
    void criarHabilidadeCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]);
    void criarHabilidadeCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]);
    void criarHabilidadeOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]);
    void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], 
                          int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], 
                          int centroX, int centroY);
    void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
    void exibirMatrizHabilidade(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]);
    
    int main() {
        // Inicializa o tabuleiro
        int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
        inicializarTabuleiro(tabuleiro);
        
        printf("=== BATALHA NAVAL - NIVEL MESTRE ===\n");
        printf("Tabuleiro com habilidades especiais de area\n\n");
        
        // Posiciona os navios
        posicionarNavios(tabuleiro);
        
        // Cria as matrizes de habilidade
        int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
        int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
        int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
        
        criarHabilidadeCone(cone);
        criarHabilidadeCruz(cruz);
        criarHabilidadeOctaedro(octaedro);
        
        printf("\n=== MATRIZES DE HABILIDADE ===\n");
        
        printf("\nCone (5x5):\n");
        exibirMatrizHabilidade(cone);
        
        printf("\nCruz (5x5):\n");
        exibirMatrizHabilidade(cruz);
        
        printf("\nOctaedro (5x5):\n");
        exibirMatrizHabilidade(octaedro);
        
        // Aplica as habilidades ao tabuleiro
        aplicarHabilidade(tabuleiro, cone, 2, 4);
        aplicarHabilidade(tabuleiro, cruz, 6, 3);
        aplicarHabilidade(tabuleiro, octaedro, 4, 7);
        
        // Exibe o tabuleiro final
        printf("\n=== TABULEIRO FINAL ===\n");
        printf("Legenda: 0=Agua | 3=Navio | 1=Habilidade\n");
        exibirTabuleiro(tabuleiro);
        
        return 0;
    }
    
    // Inicializa o tabuleiro com água
    void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
        for (int i = 0; i < TAM_TABULEIRO; i++) {
            for (int j = 0; j < TAM_TABULEIRO; j++) {
                tabuleiro[i][j] = AGUA;
            }
        }
    }
    
    // Posiciona os navios no tabuleiro
    void posicionarNavios(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
        // Navio horizontal (linha 2, colunas 2-4)
        for (int j = 2; j < 5; j++) {
            tabuleiro[2][j] = NAVIO;
        }
        
        // Navio vertical (coluna 7, linhas 5-7)
        for (int i = 5; i < 8; i++) {
            tabuleiro[i][7] = NAVIO;
        }
        
        // Navio diagonal decrescente (\)
        for (int i = 0; i < 3; i++) {
            tabuleiro[1+i][1+i] = NAVIO;
        }
        
        // Navio diagonal crescente (/)
        for (int i = 0; i < 3; i++) {
            tabuleiro[3+i][7-i] = NAVIO;
        }
    }
    
    // Cria matriz de habilidade em formato de cone (triângulo)
    void criarHabilidadeCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
        int centro = TAM_HABILIDADE / 2;
        for (int i = 0; i < TAM_HABILIDADE; i++) {
            for (int j = 0; j < TAM_HABILIDADE; j++) {
                // Verifica se está dentro da área triangular do cone
                if (j >= centro - i && j <= centro + i) {
                    habilidade[i][j] = 1;
                }
            }
        }
    }
    
    // Cria matriz de habilidade em formato de cruz
    void criarHabilidadeCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
        int centro = TAM_HABILIDADE / 2;
        for (int i = 0; i < TAM_HABILIDADE; i++) {
            for (int j = 0; j < TAM_HABILIDADE; j++) {
                // Verifica se está na linha ou coluna central
                if (i == centro || j == centro) {
                    habilidade[i][j] = 1;
                }
            }
        }
    }
    
    // Cria matriz de habilidade em formato de octaedro (losango)
    void criarHabilidadeOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
        int centro = TAM_HABILIDADE / 2;
        for (int i = 0; i < TAM_HABILIDADE; i++) {
            for (int j = 0; j < TAM_HABILIDADE; j++) {
                // Verifica se está dentro do losango
                if (abs(i - centro) + abs(j - centro) <= centro) {
                    habilidade[i][j] = 1;
                }
            }
        }
    }
    
    // Aplica uma habilidade ao tabuleiro
    void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], 
                          int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], 
                          int centroX, int centroY) {
        int offset = TAM_HABILIDADE / 2;
        
        for (int i = 0; i < TAM_HABILIDADE; i++) {
            for (int j = 0; j < TAM_HABILIDADE; j++) {
                // Calcula posição no tabuleiro
                int x = centroX - offset + i;
                int y = centroY - offset + j;
                
                // Verifica se está dentro do tabuleiro
                if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO) {
                    // Se a posição na matriz de habilidade for 1, marca no tabuleiro
                    if (habilidade[i][j] == 1 && tabuleiro[x][y] != NAVIO) {
                        tabuleiro[x][y] = HABILIDADE;
                    }
                }
            }
        }
    }
    
    // Exibe o tabuleiro formatado
    void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
        printf("   ");
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%2d ", j); // Cabeçalho das colunas
        }
        printf("\n");
        
        for (int i = 0; i < TAM_TABULEIRO; i++) {
            printf("%2d ", i); // Número da linha
            for (int j = 0; j < TAM_TABULEIRO; j++) {
                printf("%2d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    }
    
    // Exibe uma matriz de habilidade
    void exibirMatrizHabilidade(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
        for (int i = 0; i < TAM_HABILIDADE; i++) {
            for (int j = 0; j < TAM_HABILIDADE; j++) {
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
    }
}
