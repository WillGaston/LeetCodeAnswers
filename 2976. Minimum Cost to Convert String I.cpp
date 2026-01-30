class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // source --> target but can only swap original letters to changed letters
        // each letter is a node - changed/original pairs are edges
        // to go from one letter or source to the letter of target compute the cost as the sum of edges on path from oeriginal to changed letter

        // dp[i][j] is the cost to go from letter i to letter j <== mimic floyd-warshall

        vector<vector<long long>> dp(26, vector<long long>(26, INT_MAX));

        for (int i = 0; i < 26; i++) dp[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            dp[original[i] - 'a'][changed[i] - 'a'] = min(dp[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        long long minC = 0;

        for (int i = 0; i < target.size(); i++) {
            long long c = dp[source[i] - 'a'][target[i] - 'a'];
            if (c < INT_MAX) minC += c;
            else return -1;
        }

        return minC;
    }
};
