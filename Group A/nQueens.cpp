#include <iostream>
#include <vector>

using namespace std;

// Function to print the current board state
void printSolution(vector<vector<int>>& board) {
    int N = board.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (board[i][j])
                cout << "Q ";
            else 
                cout << ". ";
        cout << "\n";
    }
    cout << "\n";
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(vector<vector<int>>& board, int row, int col) {
    int N = board.size();
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check the upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check the lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

int main() {
    int N;
    cout << "Enter the size of the board (N): ";
    cin >> N;

    // vector<vector<int>> board
    vector<vector<int>> board(N, vector<int>(N, 0));

    int queensPlaced = 0;
    while (queensPlaced < N) {
        int row, col;
        cout << "Enter the row and column to place the Queen (0-indexed): ";
        cin >> row >> col;

        if (row >= N || col >= N || row < 0 || col < 0) {
            cout << "Invalid position. Try again.\n";
            continue;
        }

        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            printSolution(board); // Print board after placing a queen
            queensPlaced++;
        } else {
            cout << "Placement at (" << row << ", " << col << ") is not safe. Try again.\n";
        }
    }

    cout << "All queens placed successfully:\n";
    printSolution(board);

    return 0;
}
