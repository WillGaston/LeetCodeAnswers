class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // subproblem: find the longest common subsequence from any substring of our input text
        // recurrence relation: if the current end characters are equal, we can 'fix' the character and continue building a common 
        //                      substring by reducing both substring lengths
        //                      if they characters are not equal, cannot add the chars, so equals maximum of each substr without the 
        //                      curr letter
        // order of computation: we go in reducing i and j
        // base cases: a subsequence of strings with no characters is 0
        // overall answer: dp[m][n]
        // time complexity: O(nm) we check each combination of strings each taking O(1) time

        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};
