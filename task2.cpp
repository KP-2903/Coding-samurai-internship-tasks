#include <iostream>
#include <vector>

using namespace std;

// Function to initialize the game board
vector<vector<char>> initializeBoard() {
    return {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
}

// Function to display the game board
void displayBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if there's a win
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full (draw)
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == '-') {
                return false;
            }
        }
    }
    return true;
}

// Function to handle player moves
void playerMove(vector<vector<char>>& board, char player) {
    int row, col;
    do {
        cout << "Player " << player << ", enter your move (row column): ";
        cin >> row >> col;
    } while (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-');
    board[row][col] = player;
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;

    char currentPlayer = 'X';
    vector<vector<char>> board = initializeBoard();
    displayBoard(board);

    // Main game loop
    while (true) {
        playerMove(board, currentPlayer);
        displayBoard(board);

        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        } else if (checkDraw(board)) {
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}
