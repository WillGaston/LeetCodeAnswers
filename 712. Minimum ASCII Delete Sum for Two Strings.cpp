class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // rather than delete non-same characters, we can try to find the largest common subsequence.
        // let dp[i][j] be the largest common subsequence of characters ending at s1[i] and s2[j]
        // if s[i] = s[j] we increment by cost
        // else we skip one of them
        // at the end we will have the largest sum when keeping the subsequence, so the minimum deleted sum will be the cost of the unchosen characters.

        int s1z = s1.size();
        int s2z = s2.size();
        vector<vector<int>> dp(s1z + 1, vector<int>(s2z + 1, 0));

        int totalCost = 0;
        
        for (int i = 1; i <= s1z; i++) {
            for (int j = 1; j <= s2z; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + s1[i - 1]; 
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        for (char c : s1) totalCost += c;
        for (char c : s2) totalCost += c;

        return totalCost - 2 * dp[s1z][s2z];
    }
};
