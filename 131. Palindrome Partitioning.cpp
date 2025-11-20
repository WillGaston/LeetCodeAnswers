class Solution {
public:
    vector<vector<string>> partition(string s) {
        // let dp[i][j] be a boolean value denoting if the substr starting at i and ending at j is a palindrime
        int sz = s.size();

        vector<vector<string>> palinStr;
        vector<vector<bool>> dp(sz, vector<bool>(sz, false));

        for (int i = 0; i < sz; i++) {
            dp[i][i] = true;
        }


        // must compute dp[i+1][j-1] before dp[i][j] so compute by increasing length, not start/end point
        for (int l = 2; l <= sz; l++) {
            for (int i = 0; i < sz; i++) {
                int j = l + i - 1;
                if (j >= sz) continue;
                if (l == 2 && i + 1 < sz && s[i] == s[i + 1]) dp[i][j] = true;
                else if (i + 1 < sz && j - 1 >= 0 && s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = true;
            }
        }

        vector<string> currSubstr;
        recurse(0, currSubstr, s, sz, dp, palinStr);

        return palinStr;
    }

    void recurse(int startPos, vector<string> currSubstr, string& s, int& sz, vector<vector<bool>>& dp, vector<vector<string>>& palinStr) {
        if (startPos == sz) {
            palinStr.push_back(currSubstr);
            return;
        } else {
            for (int i = startPos; i < sz; i++) {
                if (dp[startPos][i]) {
                    currSubstr.push_back(s.substr(startPos, i - startPos + 1));
                    recurse(i + 1, currSubstr, s, sz, dp, palinStr);
                    currSubstr.pop_back();
                }
            }
        }
    }
};
