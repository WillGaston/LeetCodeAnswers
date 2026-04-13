class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        return (min(abs(propagate(1, start, target, nums) - start), abs(propagate(-1, start, target, nums) - start)));
    }
    
    int propagate(int dir, int startIndex, int& target, vector<int>& nums) {
        for (int i = startIndex; (dir == 1) ? (i < nums.size()) : (i >= 0); (dir == 1) ? i++ : i--) {
            if (target == nums[i]) return i;
        }
        return INT_MAX;
    }

};
