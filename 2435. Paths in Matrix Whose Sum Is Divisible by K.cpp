class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        // dp[i][j][k] is the number of paths ending at i,j with a mod value of k
        // dp[i][j][k] = dp[i - 1][j][k + grid[i][j] % k]
        // dp[i][j][k] += dp[i][j - 1][k + grid[i][j] % k]

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k, 0)));

        dp[1][1][grid[0][0] % k] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int r = 0; r < k; r++) {
                    int newRem = (r + grid[i - 1][j - 1]) % k;
                    dp[i][j][newRem] = (dp[i][j][newRem] + dp[i - 1][j][r]) % 1000000007;
                    dp[i][j][newRem] = (dp[i][j][newRem] + dp[i][j - 1][r]) % 1000000007;
                }
            }
        }

        return dp[m][n][0];
    }
};
