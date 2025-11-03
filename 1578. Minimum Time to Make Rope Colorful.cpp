class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        vector<int> dp;
        dp.push_back(0);
        // let dp[i] be the minimum total time up to ballon i
        // two cases:
        // 1) adjacent same color
        //    - check if using current or previous gives smaller cost
        //    - see if using the previous cost or current cost is minimum
        //    - update current cost to reflect updated costs - take the max of the last two costs to be neededTime[i]
        // 2) different colors
        //    - we do not need to do anything so just continue from prev


        // this essentially groups the costs of same color groups.
        // for each new ballon of the same color, we only ever have one ballon useable
        // we see if using the current or the previous is better - and update the neededTime to reflect our choice of which one is still usable

        int n = colors.size();

        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                dp.push_back(dp[i - 1] + min(neededTime[i], neededTime[i - 1]));
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            } else {
                dp.push_back(dp[i - 1]);
            }
        }

        return dp[n - 1];
    }
};
