class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
       vector<int> ans;
       int nz = nums.size();

       for (int i = 0; i < nz; i++) {
        if (nums[i] % 2 == 0) {
            nums[i] = -1;
        } else {
            for (int j = 0; j < nums[i]; j++) {
                if ((j | (j + 1)) == nums[i]) {
                    nums[i] = j;
                }
            }
        }
       }

        return nums;
    }
};
