#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Initialize the board
void initializeBoard() {
    char num = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }

    currentPlayer = 'X';
}

// Display the board
void displayBoard() {
    cout << "\n";

    for (int i = 0; i < 3; i++) {
        cout << " ";

        for (int j = 0; j < 3; j++) {
            cout << board[i][j];

            if (j < 2)
                cout << " | ";
        }

        cout << "\n";

        if (i < 2)
            cout << "---|---|---\n";
    }

    cout << "\n";
}

// Check for winner
bool checkWin() {

    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

// Check for draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

// Handle player move
void playerMove() {
    int choice;

    cout << "Player " << currentPlayer
         << ", enter position (1-9): ";
    cin >> choice;

    if (choice < 1 || choice > 9) {
        cout << "Invalid position! Try again.\n";
        playerMove();
        return;
    }

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] == 'X' ||
        board[row][col] == 'O') {

        cout << "Position already taken! Try again.\n";
        playerMove();
        return;
    }

    board[row][col] = currentPlayer;
}

// Switch players
void switchPlayer() {
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

// Main function
int main() {

    char playAgain;

    do {
        initializeBoard();

        bool gameOver = false;

        while (!gameOver) {

            displayBoard();

            playerMove();

            if (checkWin()) {

                displayBoard();

                cout << "Player "
                     << currentPlayer
                     << " wins!\n";

                gameOver = true;
            }
            else if (checkDraw()) {

                displayBoard();

                cout << "The game is a draw!\n";

                gameOver = true;
            }
            else {
                switchPlayer();
            }
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for playing Tic-Tac-Toe!\n";

    return 0;
}
