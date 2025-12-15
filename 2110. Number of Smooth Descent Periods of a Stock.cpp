class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long numPeriods = 1;
        long long counter = 1;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] == prices[i - 1] - 1) {
                counter++;
            } else {
                counter = 1;
            }

            numPeriods += counter;
        }

        return numPeriods;
    }
};
