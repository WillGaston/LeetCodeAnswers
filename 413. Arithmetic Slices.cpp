class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // since we always consider 3 numbers in the slice, we can create a dp solution which succeeds from one prior subproblem
        // we can easily extend a slice as long as two overlap with the previous slice, so only consider 1 dimension

        int nz = nums.size();

        // let dp[i] be the number of slices from 0 to i
        // each of those slices is unique as the size is at least 3 and so contributes to the total number
        vector<int> dp(nz, 0);
        int total = 0;

        for (int i = 2; i < nz; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }

            total += dp[i];
        }

        return total;
    }
};
