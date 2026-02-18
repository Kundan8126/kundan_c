#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8   // Board size
#define MINES 10 // Number of mines

char board[SIZE][SIZE];   // Player's board
char realBoard[SIZE][SIZE]; // Actual board with mines
int revealed[SIZE][SIZE];  // To track revealed cells

// Directions for checking adjacent cells
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
            realBoard[i][j] = '-';
            revealed[i][j] = 0;
        }
    }
}

// Function to place mines randomly
void placeMines() {
    srand(time(NULL));
    int count = 0;
    while (count < MINES) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (realBoard[x][y] != '*') {
            realBoard[x][y] = '*';
            count++;
        }
    }
}

// Function to count adjacent mines
int countAdjacentMines(int x, int y) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && realBoard[nx][ny] == '*') {
            count++;
        }
    }
    return count;
}

// Function to reveal a cell
void revealCell(int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || revealed[x][y])
        return;
    
    revealed[x][y] = 1;
    int mines = countAdjacentMines(x, y);
    board[x][y] = mines + '0';

    if (mines == 0) { // If no adjacent mines, reveal neighboring cells
        for (int i = 0; i < 8; i++) {
            revealCell(x + dx[i], y + dy[i]);
        }
    }
}

// Function to display the board
void printBoard() {
    printf("\n   ");
    for (int i = 0; i < SIZE; i++) printf("%d ", i);
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d  ", i);
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j])
                printf("%c ", board[i][j]);
            else
                printf("- ");
        }
        printf("\n");
    }
}

// Function to check if the player has won
int checkWin() {
    int count = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (!revealed[i][j] && realBoard[i][j] != '*')
                count++;
    return count == 0;
}

// Main game function
void playGame() {
    int x, y;
    initializeBoard();
    placeMines();
    
    while (1) {
        printBoard();
        printf("Enter row and column (x y): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
            printf("Invalid input! Try again.\n");
            continue;
        }
        if (realBoard[x][y] == '*') {
            printf("\nBOOM! You hit a mine! Game Over.\n");
            return;
        }

        revealCell(x, y);
        if (checkWin()) {
            printBoard();
            printf("\nCongratulations! You won!\n");
            return;
        }
    }
}

// Main function
int main() {
    printf("Welcome to Minesweeper!\n");
    playGame();
    return 0;
}