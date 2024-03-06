#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3]; // 3x3 Tic Tac Toe board
    char currentPlayer; // Current player: 'X' or 'O'

public:
    TicTacToe() {
        // Initialize the board with empty spaces
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        // Player 'X' starts the game
        currentPlayer = 'X';
    }

    // Method to display the Tic Tac Toe board
    void displayBoard() {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " | ";
            }
            cout << endl;
            cout << "-------------" << endl;
        }
    }

    // Method to check if the move is valid
    bool isValidMove(int row, int col) {
        // Check if the position is within the board limits and the position is not already occupied
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }

    // Method to make a move on the board
    void makeMove(int row, int col) {
        if (isValidMove(row, col)) {
            board[row][col] = currentPlayer;
            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    }

    // Method to check if the game is won
    bool checkWin() {
        // Check rows and columns for a win
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                return true; // Row win
            }
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
                return true; // Column win
            }
        }
        // Check diagonals for a win
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            return true; // Diagonal win (top-left to bottom-right)
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return true; // Diagonal win (top-right to bottom-left)
        }
        return false; // No win
    }

    // Method to check if the board is full
    bool isBoardFull() {
        // Check if there are any empty spaces left
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false; // Board is not full
                }
            }
        }
        return true; // Board is full
    }

    // Method to get the current player
    char getCurrentPlayer() {
        return currentPlayer;
    }
};

int main() {
    TicTacToe game;
    int row, col;

    cout << "Welcome to Tic Tac Toe!" << endl;

    while (!game.isBoardFull()) {
        game.displayBoard();
        cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column): ";
        cin >> row >> col;
        game.makeMove(row, col);
        if (game.checkWin()) {
            game.displayBoard();
            cout << "Player " << game.getCurrentPlayer() << " wins!" << endl;
            return 0;
        }
    }

    cout << "It's a draw!" << endl;
return 0;

}
