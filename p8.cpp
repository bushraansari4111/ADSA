#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void solve(vector<string>& board, int row, int n, int& count) {
    if (row == n) {
        count++;
        cout << "Solution " << count << ":\n";
        for (const string& row : board)
            cout << row << '\n';
        cout << '\n';
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(board, row + 1, n, count);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> board(n, string(n, '.'));
    int count = 0;

    solve(board, 0, n, count);

    if (count == 0)
        cout << "No solution exists\n";
    else
        cout << "Total Solutions: " << count << '\n';

    return 0;
}
//input-4
//OUTPUT-Solution 1:
// .Q..
// ...Q
// Q...
// ..Q.

// Solution 2:
// ..Q.
// Q...
// ...Q
// .Q..

// Total Solutions: 2

