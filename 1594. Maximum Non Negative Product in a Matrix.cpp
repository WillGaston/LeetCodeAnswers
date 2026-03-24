class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, 0)));
        // dp[i][j][0] = highest value ending at i, j
        // dp[i][j][1] = lowest valuie ending at i, j
        dp[0][0][0] = grid[0][0];
        dp[0][0][1] = grid[0][0];

        for (int i = 1; i < m; i++) {
            dp[i][0][0] = max(dp[i - 1][0][0] * grid[i][0], dp[i - 1][0][1] * grid[i][0]);
            dp[i][0][1] = min(dp[i - 1][0][0] * grid[i][0], dp[i - 1][0][1] * grid[i][0]);
        }

        for (int i = 1; i < n; i++) {
            dp[0][i][0] = max(dp[0][i - 1][0] * grid[0][i], dp[0][i - 1][1] * grid[0][i]);
            dp[0][i][1] = min(dp[0][i - 1][0] * grid[0][i], dp[0][i - 1][1] * grid[0][i]);
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int curr = grid[i][j];
                if (curr >= 0) {
                    dp[i][j][0] = max(dp[i - 1][j][0] * curr, dp[i][j - 1][0] * curr); 
                    dp[i][j][1] = min(dp[i - 1][j][1] * curr, dp[i][j - 1][1] * curr); 
                } else if (curr < 0) {
                    dp[i][j][0] = max(dp[i - 1][j][1] * curr, dp[i][j - 1][1] * curr); 
                    dp[i][j][1] = min(dp[i - 1][j][0] * curr, dp[i][j - 1][0] * curr);
                }
            }
        }

        return (dp[m - 1][n - 1][0] >= 0) ? dp[m - 1][n - 1][0] % 1000000007 : -1;
    }
};
