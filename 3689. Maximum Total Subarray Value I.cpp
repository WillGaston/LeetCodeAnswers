class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int minimum = INT_MAX;
        int maximum = INT_MIN;

        for (int num : nums) {
            maximum = max(maximum, num);
            minimum = min(minimum, num);
        }

        return 1LL * k * (maximum - minimum);
    }
};
