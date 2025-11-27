class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // let dp[i] be the number fo ways to make amount i
        // dp[i] += dp[i - coins[j]]

        vector<long long> dp(amount + 1, 0);

        int cz = coins.size();
        dp[0] = 1;

        for (int j = 0; j < cz; j++) {
            for (int i = coins[j]; i <= amount; i++) {
                dp[i] += (long long)dp[i - coins[j]] % INT_MAX;
            }
        }

        return dp[amount];
    }
};
