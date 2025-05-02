#include <bits/stdc++.h>
using namespace std;
void printSolution(vector<vector<int>>& board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if(board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        cout << "\n";
    }
}
bool isSafe(vector<vector<int>>& board, int current_row, int current_col) {
    int n = board.size();
    int row, col;
    for (col = 0; col < current_col; col++)
        if (board[current_row][col])
            return false;
    for (row = current_row-1, col = current_col-1; row >= 0 && col >= 0; row--, col--)
        if (board[row][col])
            return false;
    for (row = current_row+1, col = current_col-1; col>= 0 && row < n; row++, col--)
        if (board[row][col])
            return false;
    return true;
}

bool solveNQUtil(vector<vector<int>>& board, int current_col) {
    int n = board.size();
    if (current_col >= n)
        return true;
    for (int row = 0; row < n; row++) {
        if (isSafe(board, row, current_col)) {
            board[row][current_col] = 1;
            if (solveNQUtil(board, current_col + 1))
                return true;
            board[row][current_col] = 0; // BACKTRACK
        }
    }
    return false;
}

int main() {
    int n = 4;
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (solveNQUtil(board, 0) == false) {
        cout << "Solution does not exist";
      }
else{
    printSolution(board);
}
    return 0;
}