class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1) return 0;
        if (m == 1 && n == 1) return 1;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // number of paths ending at m,n
        dp[1][1] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) continue;
                if (obstacleGrid[i - 1][j - 1] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }

        return dp[m][n];
    }
};
