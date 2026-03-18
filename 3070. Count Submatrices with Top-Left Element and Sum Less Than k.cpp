class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        // dp[i][j] is the size of submatrix with i,j as the bottom right corner
        // if valid, increment

        int m = grid.size();
        int n = grid[0].size();
        int num = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];
        if (dp[0][0] <= k) num++;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (i == 0) dp[i][j] = dp[i][j - 1] + grid[i][j];
                else if (j == 0) dp[i][j] = dp[i - 1][j] + grid[i][j];
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + grid[i][j];

                if (dp[i][j] <= k) num++;
            }
        }

        return num;
    }
};
