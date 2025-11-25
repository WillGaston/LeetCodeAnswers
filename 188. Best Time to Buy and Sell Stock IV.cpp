class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // let buy[i][j] be the profit made from the first i products with j transactions
        // let sell[i][j] be the profit made from the first i products with j transactions

        // at each day we can buy, sell, or do nothing
        // buy[i][j] = max(buy[i - 1][j], sell[i - 1][j - 1] - prices[i]) // do nothing, or buy new thing
        // sell[i][j] = max(buy[i - 1][j] + prices[i], sell[i - 1][j]) // sell or do nothing

        int pz = prices.size();
        vector<vector<int>> buy(pz, vector<int>(k + 1, INT_MIN));
        vector<vector<int>> sell(pz, vector<int>(k + 1, 0));

        for (int i = 1; i <= k; i++) {
            buy[0][i] = -1 * prices[0];
        }

        for (int i = 1; i < pz; i++) {
            for (int j = 1; j <= k; j++) {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j - 1] - prices[i]);
                sell[i][j] = max(buy[i - 1][j] + prices[i], sell[i - 1][j]);
            }
        }

        return sell[pz - 1][k];
    }
};
