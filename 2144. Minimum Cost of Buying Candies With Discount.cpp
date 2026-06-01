class Solution {
public:
    int minimumCost(vector<int>& cost) {
        // greedy approach - buying the highest + 2nd highest lets us get the third highest for free every time
        int minCost = 0;

        sort(cost.begin(), cost.end());

        int r = cost.size() - 1;

        while (r >= 0) {
            if (r - 1 >= 0) minCost += cost[r] + cost[r - 1];
            else minCost += cost[r];
            r -= 3;
        }

        return minCost;
    }
};
