class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n, 0);
        vector<int> sell(n, 0);
        vector<int> rest(n, 0);
        // dp[i] means ith profit on ith buying day i or selling on day i

        sell[0] = 0;
        buy[0] = -1 * prices[0];
        rest[0] = 0;

        for (int i = 1; i < n; i++) {
            buy[i] = max(buy[i-1], rest[i - 1] - prices[i]);
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
            rest[i] = max(rest[i - 1], sell[i - 1]);
        }

        return max(sell[n - 1], rest[n - 1]);
    }
};
