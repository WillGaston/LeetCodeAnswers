class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       // let balance[i] be the the balance from buying/having an active trade from 1..i
       // let profit[i] be the profit from selling/having no active trade from 1..i

       // each time we buy, we also account for the transaction fee

       // balance[i] = max(balance[i - 1], profit[i - 1] - prices[i] - fee) // do nothing or buy
       // profit[i] = max(profit[i - 1], balance[i - 1] + prices[i]) // do nothing or sell

        int pz = prices.size();
        vector<int> balance(pz, INT_MIN);
        vector<int> profit(pz, 0);

        for (int i = 0; i < pz; i++) {
            balance[i] = -1 * (prices[i] + fee);
        }

        for (int i = 1; i < pz; i++) {
            balance[i] = max(balance[i - 1], profit[i - 1] - prices[i] - fee);
            profit[i] = max(profit[i - 1], balance[i - 1] + prices[i]);
        }

       return profit[pz - 1];
    }
};
