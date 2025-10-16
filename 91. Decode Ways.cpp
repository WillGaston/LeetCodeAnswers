class Solution {
public:
    int numDecodings(string s) {        
        // dp[i] is a list of the number of possible decodings using the first i chars
        int size = s.size();
        vector<int> dp(size + 1, 0);
        
        dp[1] = 1;
        dp[0] = 1;
        if (s[0] == '0') return 0;

        for (int i = 2; i <= size; i++) {
            // use i as either a single char code
            // use i as part of a two letter code

            if (s[i - 1] != '0') dp[i] = dp[i - 1];
            if (s[i - 2] != '1' && s[i - 2] != '2') continue;
            if (s[i - 2] == '2' && (s[i - 1] == '7' || s[i - 1] == '8' || s[i - 1] == '9')) continue;

            dp[i] += dp[i - 2];
        }

        return dp[size];
    }
};
