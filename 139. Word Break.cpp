class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // let dp[i] be a boolean describing if we can have a valid list ending at index i
        int sz = s.size();
        vector<bool> dp(sz + 1, false);

        dp[0] = true;

        for (int i = 1; i <= sz; i++) {
            // check if we can have wd as the previous word ending at i
            for (string& wd : wordDict) {
                if (int(i - wd.size()) >= 0 && dp[i - wd.size()] && s.substr(i - wd.size(), wd.size()) == wd) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[sz];
    }
};
