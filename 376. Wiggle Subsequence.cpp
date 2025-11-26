class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // can be decomposed into the largest alternating subsequence
        // 1 means positive, 0 means negative

        // let dp[i][j] be the largest alternating subsequence ending at i where the last difference was j (pos or neg)
        // if i is pos, append to neg
        // if i is neg, append to pos

        if (nums.size() == 1) return 1;
        
        int nz = nums.size();
        vector<int> diffs;

        for (int i = 0; i < nz - 1; i++) {
            int diff = nums[i + 1] - nums[i];
            if (diff > 0) diffs.push_back(1);
            else if (diff < 0) diffs.push_back(0);
        }

        int dz = diffs.size();
        if (dz == 0) return 1;
        vector<vector<int>> dp(dz, vector<int>(2, 1));

        if (diffs[0] > 0) {
            dp[0][1] = 2;
        } else {
            dp[0][0] = 2;
        }

        for (int i = 1; i < dz; i++) {
            if (diffs[i] > 0) {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = 1 + dp[i][0];
            } else {
                dp[i][1] = dp[i - 1][1];
                dp[i][0] = 1 + dp[i][1];
            }
        }

        return max(dp[dz - 1][0], dp[dz - 1][1]);
    }
};
