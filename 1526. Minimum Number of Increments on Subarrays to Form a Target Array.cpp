class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int currHeight = 0;
        int currOps = 0;

        for (int num : target) {
            if (num > currHeight) {
                currOps += (num - currHeight);
            }
            currHeight = num;
        }

        return currOps;
    }
};
