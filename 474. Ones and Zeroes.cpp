class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[i][j] represents the max size of a subset using i 0s and j 1s

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        map<int, vector<int>> mp; // 0 = 0, 1 = 1
        int mx = 0;

        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            int num0 = 0;
            int num1 = 0;
            for (char c : str) {
                if (c == '1') num1++;
                else num0++;
            }
            mp[i] = {num0, num1};
        }

        for (int k = 0; k < strs.size(); k++) {
            int num0 = mp[k][0];
            int num1 = mp[k][1];
            for (int i = m; i >= 0; i--) {
                for (int j = n; j >= 0; j--) {
                    if ((i - num0 >= 0) && (j - num1 >= 0)) dp[i][j] = max(dp[i][j], 1 + dp[i - num0][j - num1]);
                    mx = max(mx, dp[i][j]);
                }
            }
        }

        return mx;

    }
};
