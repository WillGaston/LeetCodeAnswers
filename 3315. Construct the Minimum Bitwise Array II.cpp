class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        // we want to remove the leftmost one in the rightmost group of 1s.
        
        for (int i = 0; i < n; i++) {
            if ((nums[i] & 1) == 0) {
                ans[i] = -1;
            } else {
                int pos = 0;
                int temp = nums[i];
                
                while ((temp & 1) == 1) {
                    temp >>= 1;
                    pos++;
                }
                
                ans[i] = nums[i] - (1 << (pos - 1));
            }
        }
        
        return ans;
    }
};
