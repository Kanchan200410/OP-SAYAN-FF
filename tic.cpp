#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';  // Player X starts the game
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int isWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return 1;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return 1;
    }
    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return 1;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return 1;
    return 0;
}

int isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void makeMove() {
    int row, col;
    while (1) {
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = currentPlayer;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int main() {
    initializeBoard();
    printf("Welcome to Tic-Tac-Toe!\n");
    printBoard();
    
    while (1) {
        makeMove();
        printBoard();
        if (isWinner()) {
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        if (isDraw()) {
            printf("It's a draw!\n");
            break;
        }
        switchPlayer();
    }

    return 0;
}