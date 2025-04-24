#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

// Representação das peças
char board[SIZE][SIZE] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

// Imprime o tabuleiro
void print_board() {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Converte coordenadas tipo "e2" para índices da matriz
void coord_to_index(char* coord, int* row, int* col) {
    *col = coord[0] - 'a';
    *row = 8 - (coord[1] - '0');
}

// Move uma peça
void move_piece(char* from, char* to) {
    int from_row, from_col, to_row, to_col;
    coord_to_index(from, &from_row, &from_col);
    coord_to_index(to, &to_row, &to_col);

    // Verifica se há peça na origem
    if (board[from_row][from_col] == ' ') {
        printf("Nenhuma peça na casa %s.\n", from);
        return;
    }

    // Move a peça
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = ' ';
    printf("Movido de %s para %s.\n", from, to);
}

int main() {
    char from[3], to[3];

    while (1) {
        print_board();
        printf("Digite a origem (ex: e2) ou 'sair': ");
        scanf("%s", from);
        if (strcmp(from, "sair") == 0) break;

        printf("Digite o destino (ex: e4): ");
        scanf("%s", to);

        move_piece(from, to);
    }

    return 0;
}