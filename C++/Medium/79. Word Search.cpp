/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent
cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Input:
board =
[["A","B","C","E"],
 ["S","F","C","S"],
 ["A","D","E","E"]], word = "ABCCED"
Output: true
*/

#include <iostream>
#include <vector>
using namespace std;

void printV(const vector<vector<char>> &vec) {
    for (const auto &row: vec) {
        for (auto val: row)
            cout << val << " ";
        cout << endl;
    }
}

class Solution2 {    // 588ms    11mb    unnecessary 'find' calls
public:
    bool find(vector<vector<char>> &board, vector<vector<bool>> &used, int row, int col, string &word, int cur) {
        if (cur == word.size())
            return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || used[row][col] || board[row][col] != word[cur])
            return false;
        used[row][col] = true;
        bool found = find(board, used, row - 1, col, word, cur + 1) || // Up
                     find(board, used, row + 1, col, word, cur + 1) || // Down
                     find(board, used, row, col - 1, word, cur + 1) || // Left
                     find(board, used, row, col + 1, word, cur + 1);   // Right
        used[row][col] = false;
        return found;
    }

    bool exist(vector<vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == word[0]) {
                    vector used(board.size(), vector(board[0].size(), false));
                    if (find(board, used, i, j, word, 0))
                        return true;
                }
        return false;
    }
};

class Solution3 {    // 359ms    11mb    no unnecessary calls    worst case: O(m*n*4^k)
public:
    bool find(vector<vector<char>> &board, vector<vector<bool>> &used, int row, int col, string &word, int cur, int m, int n) {
        if (cur == word.size())
            return true;
        used[row][col] = true;
        bool found = false;
        if (row > 0 && !used[row - 1][col] && board[row - 1][col] == word[cur]) // up
            found = find(board, used, row - 1, col, word, cur + 1, m, n);
        if (!found && row < m - 1 && !used[row + 1][col] && board[row + 1][col] == word[cur]) // down
            found = find(board, used, row + 1, col, word, cur + 1, m, n);
        if (!found && col > 0 && !used[row][col - 1] && board[row][col - 1] == word[cur]) // left
            found = find(board, used, row, col - 1, word, cur + 1, m, n);
        if (!found && col < n - 1 && !used[row][col + 1] && board[row][col + 1] == word[cur]) // right
            found = find(board, used, row, col + 1, word, cur + 1, m, n);
        used[row][col] = false;
        return found;
    }

    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == word[0]) {
                    vector used(m, vector(n, false));
                    if (find(board, used, i, j, word, 1, m ,n))
                        return true;
                }
        return false;
    }
};

class Solution {    // 139ms    10mb    no extra 'used' board
public:
    bool find(vector<vector<char>> &board, int row, int col, string &word, int cur, int m, int n) { // dfs
        if (cur == word.size())
            return true;
        char temp = board[row][col];
        board[row][col] = '#';  // Mark as visited
        bool found = false;
        if (row > 0 && board[row - 1][col] == word[cur]) // up
            found = find(board, row - 1, col, word, cur + 1, m, n);
        if (!found && row < m - 1 && board[row + 1][col] == word[cur]) // down
            found = find(board, row + 1, col, word, cur + 1, m, n);
        if (!found && col > 0 && board[row][col - 1] == word[cur]) // left
            found = find(board, row, col - 1, word, cur + 1, m, n);
        if (!found && col < n - 1 && board[row][col + 1] == word[cur]) // right
            found = find(board, row, col + 1, word, cur + 1, m, n);
        board[row][col] = temp;
        return found;
    }

    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == word[0]) {
                    if (find(board, i, j, word, 1, m ,n))
                        return true;
                }
        return false;
    }
};

int main() {
    Solution test;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    printV(board);
    cout << test.exist(board, "ABCCED");
    return 0;
}
