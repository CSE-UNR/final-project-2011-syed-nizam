//2011-syed-nizam
//CS135 FINAL PROJECT - BATSHIP

#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10
#define SHIPCOUNT 5

void showFile(char board[ROWS][COLS]);
bool sunkShips(char board[ROWS][COLS]);
void startFile(char playerBoard[ROWS][COLS], char guessBoard[ROWS][COLS]);
bool shipHit(char board[ROWS][COLS], int row, int col);
void ships(char board[ROWS][COLS]);
void userInput(int *row, int *col);
void playGame();

int main() {
    playGame();
    return 0;
}

void startFile(char playerBoard[ROWS][COLS], char guessBoard[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            playerBoard[i][j] = ' ';
            guessBoard[i][j] = ' ';
        }
    }
}

void showFile(char board[ROWS][COLS]) {
    printf("  ");
    for (int i = 0; i < COLS; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
   
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);
        if (i < 10) printf(" "); 
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void ships(char board[ROWS][COLS]) {
    int shipPositions[SHIPCOUNT][2] = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}}; 
   
    for (int i = 0; i < SHIPCOUNT; i++) {
        int row = shipPositions[i][0];
        int col = shipPositions[i][1];
        board[row][col] = 'S';
    }
}

bool shipHit(char board[ROWS][COLS], int row, int col) {
    return board[row][col] == 'S';
}

bool sunkShips(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 'S') {
                return false;
            }
        }
    }
    return true;
}

void userInput(int *row, int *col) {
    char colInput;
    do {
        printf("Enter a spot in the grid to shoot your shot; first enter row and then column: ");
        scanf("%d %c", row, &colInput);
        *col = colInput - 'A';
    } while (*row < 0 || *row >= ROWS || *col < 0 || *col >= COLS);
}

void playGame() {
    char playerBoard[ROWS][COLS];
    char guessBoard[ROWS][COLS];
    int row, col;
    int score = 0;
   
    startFile(playerBoard, guessBoard);
    ships(playerBoard);
   
    while (!sunkShips(playerBoard)) {
        showFile(guessBoard);
        userInput(&row, &col);
       
        if (shipHit(playerBoard, row, col)) {
            printf("Hit!\n");
            guessBoard[row][col] = 'X';
            playerBoard[row][col] = ' ';
            score++;
        } else {
            printf("Miss.\n");
            guessBoard[row][col] = '0';
        }
    }
   
    printf("Congratulations! You are amazing! You sunk all the ships!\n");
    printf("Your score: %d\n", score);
   
    char playAgain;
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &playAgain);
    if (playAgain == 'y' || playAgain == 'Y') {
        playGame();
    } else {
        printf("Thanks for playing!\n");
    }
}
