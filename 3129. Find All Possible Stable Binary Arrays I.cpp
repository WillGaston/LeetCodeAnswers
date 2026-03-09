class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        // dp[i][j][l], where:
        //  - i is number of one
        //  - j is number of zero
        //  - k is the number of consecutive, equal end-of-array values - we can remove this and add specific limit threshold checks
        //  - l is the last digit

        vector<vector<vector<long long>>> dp(one + 1, vector<vector<long long>>(zero + 1, vector<long long> (2, 0)));

        for (int i = 0; i <= min(one, limit); i++) dp[i][0][1] = 1;
        for (int i = 0; i <= min(zero, limit); i++) dp[0][i][0] = 1;
        
        // essentially a more complex prefix sum

        for (int i = 1; i <= one; i++) {
            for (int j = 1; j <= zero; j++) {
                // attempt to append 1
                
                // need to ensure don't cross limit threshold - reset count for items crossing threshold - if we are adding 1 then any scenario already with lots of zeroes will cross threshold, so remove them
                dp[i][j][1] = (dp[i - 1][j][1] + dp[i - 1][j][0]) % 1000000007;
                if (i > limit) dp[i][j][1] = (dp[i][j][1] - dp[i - limit - 1][j][0] + 1000000007) % 1000000007;

                dp[i][j][0] = (dp[i][j - 1][1] + dp[i][j - 1][0]) % 1000000007;
                if (j > limit) dp[i][j][0] = (dp[i][j][0] - dp[i][j - limit - 1][1] + 1000000007) % 1000000007;
            }
        }

        return (int)((dp[one][zero][0] + dp[one][zero][1]) % 1000000007);
    }
};
