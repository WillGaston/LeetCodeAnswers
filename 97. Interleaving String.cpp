class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // let dp[i][j] be the subsequence using the 1st i chars of s1 and 1st j chars of s2 
        int s1s = s1.size();
        int s2s = s2.size();

        if (s3.size() != s1s + s2s) return false;

        vector<vector<bool>> dp(s1s + 1, vector<bool>(s2s + 1, false));

        for (int i = 0; i <= s1s; i++) {
            for (int j = 0; j <= s2s; j++) {
                // if neither i nor j are contributing then we can it is a substr (as "" substr of anything)
                if (i == 0 && j == 0) dp[0][0] = true;
                // if either string is empty then only the other is considered
                else if (i == 0) dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                else if (j == 0) dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                // if both strings are non-empty, we consider arriving from i or j
                else dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
            }
        }

        return dp[s1s][s2s];
    }
};
