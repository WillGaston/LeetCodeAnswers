class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // let dp[i][j] be the amount of water in the glass in the jth column of the ith row
        // use this to simulate the amount of champagne which flows through a glass. if < 1, then cannot flow to glasses below

        vector<vector<double>> dp(100, vector<double>(100, 0));

        dp[0][0] = poured;

        for (int i = 0; i < query_row; i++) {
            for (int j = 0; j <= i; j++) {
                double flowThrough = (dp[i][j] - 1.0) / 2.0;
                if (dp[i][j] > 1) {
                    dp[i + 1][j] += flowThrough;
                    dp[i + 1][j + 1] += flowThrough;
                }
            }
        }

        return min(1.0, dp[query_row][query_glass]);
    }
};
