class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int nz = nums.size();
        int l = 0;
        int r = 0;
        int ans = 1;

        for (; r < nz; r++) {
            while (nums[r] > (long long)nums[l] * k) l++;
            ans = max(ans, r - l + 1);
        }

        return nz - ans;
    }
};
