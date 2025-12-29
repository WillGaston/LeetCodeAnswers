class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int leading = 0; // this will be the iterating pointer
        int currPos = 0; // this will be the end of the modified array
        int nz = nums.size();

        while (leading < nz) {
            if (leading < 2 || nums[currPos - 2] != nums[leading]) {
                nums[currPos] = nums[leading];
                currPos++;
            }
            leading++;
        }

        return currPos;
    }
};
