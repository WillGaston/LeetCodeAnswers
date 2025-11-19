class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int currVal = original;
        set<int> s;

        for (int num : nums) {
            s.insert(num);
        }

        while (true) {
            if (s.contains(currVal)) {
                currVal <<= 1;
            }
            else break;
        }

        return currVal;
    }
};
