class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int longest = 0;
        int sz = s.size();

        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        // dp[i][j] = the maximum palindromic subsequence starting at i and ending at j

        for (int i = 0; i < sz; i++) {
            dp[i][i] = 1;
        }

        for (int l = 2; l <= sz; l++) {
            for (int i = 0; l + i - 1 < sz; i++) {
                int j = l + i - 1;
                if (l == 2 && s[i] == s[j]) {
                    dp[i][j] = 2;
                } else if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][sz - 1];
    }
};
