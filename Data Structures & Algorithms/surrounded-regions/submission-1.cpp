#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis) {
        vis[row][col] = 2;

        int n = board.size();
        int m = board[0].size();

        int delRow[] = {0, +1, 0, -1};
        int delCol[] = {-1, 0, +1, 0};

        for (int i = 0; i < 4; ++i) { // Corrected to iterate over 4 directions
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] != 2 &&
                board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return; // Edge case: empty board
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Mark all 'O' on the borders and their connected 'O's
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O') {
                    dfs(i, j, board, vis);
                }
            }
        }

        // Flip all unvisited 'O' to 'X'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O' && vis[i][j] != 2) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
