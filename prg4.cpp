
#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Display the game board
void displayBoard() {
    cout << "\n";
    cout << "     |     |     \n";
    for (int i = 0; i < 3; i++) {
        cout << "  ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2)
                cout << "  |  ";
        }
        cout << "\n";
        if (i < 2)
            cout << "_____|_____|_____\n";
    }
    cout << "     |     |     \n\n";
}

// Check winning conditions
bool checkWin(char player) {

    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

// Check whether the board is full
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

// Main game function
int main() {
    char currentPlayer = 'X';
    int choice;
    int row, col;

    cout << "============================\n";
    cout << "       TIC TAC TOE GAME\n";
    cout << "============================\n";

    while (true) {

        displayBoard();

        cout << "Player " << currentPlayer;
        cout << ", enter position (1-9): ";

        cin >> choice;

        // Validate input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Enter a number.\n";
            continue;
        }

        if (choice < 1 || choice > 9) {
            cout << "Invalid position! Choose 1-9.\n";
            continue;
        }

        // Convert position into array indexes
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Check whether position is occupied
        if (board[row][col] == 'X' ||
            board[row][col] == 'O') {
            cout << "Position already occupied! Try again.\n";
            continue;
        }

        // Place player's mark
        board[row][col] = currentPlayer;

        // Check winner
        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << "Congratulations! Player "
                 << currentPlayer << " wins!\n";
            break;
        }

        // Check draw
        if (checkDraw()) {
            displayBoard();
            cout << "Game Draw!\n";
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "\nThanks for playing!\n";

    return 0;
}
