class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // let dp[i][j] be the maximum dot product of subsequences ending at i and jth indices
        int n1z = nums1.size();
        int n2z = nums2.size();
        vector<vector<int>> dp(n1z, vector<int>(n2z, -1));
    
        for (int i = 0; i < n1z; i++) {
            for (int j = 0; j < n2z; j++) {
                dp[i][j] = nums1[i] * nums2[j]; 
            }
        }

        for (int i = 0; i < n1z; i++) {
            for (int j = 0; j < n2z; j++) {
                if (j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                if (i - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (i - 1 >= 0 && j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + nums1[i] * nums2[j]);
                dp[i][j] = max(dp[i][j], nums1[i] * nums2[j]);
            }
        }

        return  dp[n1z - 1][n2z - 1];
    }
};
