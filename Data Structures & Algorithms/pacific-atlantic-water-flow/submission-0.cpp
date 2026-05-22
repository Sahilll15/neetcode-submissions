class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        vector<vector<int>> ans;

        // Check boundaries from Pacific (left and top edges)
        for (int i = 0; i < n; ++i) {
            dfs(heights, pacific, i, 0, INT_MIN);
            dfs(heights, atlantic, i, m - 1, INT_MIN);
        }

        // Check boundaries from Atlantic (right and bottom edges)
        for (int j = 0; j < m; ++j) {
            dfs(heights, pacific, 0, j, INT_MIN);
            dfs(heights, atlantic, n - 1, j, INT_MIN);
        }

        // Find cells that can flow to both Pacific and Atlantic
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

private:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, int i, int j, int prevHeight) {
        int n = heights.size();
        int m = heights[0].size();
        
        // Check if out of bounds or already visited or not increasing in height
        if (i < 0 || i >= n || j < 0 || j >= m || ocean[i][j] || heights[i][j] < prevHeight) {
            return;
        }
        
        // Mark this cell as visited
        ocean[i][j] = 1;

        // Directions for adjacent cells
        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {-1, 0, 1, 0};

        // Explore all four directions
        for (int d = 0; d < 4; ++d) {
            int nrow = i + delRow[d];
            int ncol = j + delCol[d];
            dfs(heights, ocean, nrow, ncol, heights[i][j]);
        }
    }
};
