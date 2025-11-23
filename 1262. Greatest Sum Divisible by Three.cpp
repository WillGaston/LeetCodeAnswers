class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // subproblem: let dp[i][j] be the maximum sum starting at i where the sum %  3 == j

        int nz = nums.size();
        int pm = 0;
        vector<vector<int>> dp(nz, vector<int>(3, 0));

        for (int i = 0; i < nz; i++) {
            int mod = nums[i] % 3;
            dp[i][mod] = nums[i];
        }

        for (int i = 1; i < nz; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                int mod = (dp[i - 1][j] + nums[i]) % 3;
                dp[i][mod] = max(dp[i][mod], dp[i - 1][j] + nums[i]);
            }
            pm = max(pm, dp[i][0]);
        }

        return pm;
    }
};
