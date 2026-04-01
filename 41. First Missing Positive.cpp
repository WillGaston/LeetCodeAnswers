class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // remove items greater than nz or less than 0 - replace with 0 (tombstone)
        // need to add extra 0 to nums to ensure that arrs without 0 still return correct result (due to indexing)
        int nz = nums.size(); // extra space would just remove this var
        bool hasN = false;

        for (int i = 0; i < nz; i++) {
            if (nums[i] == nz) hasN = true;
            if (nums[i] < 0 || nums[i] >= nz) nums[i] = 0;
        }
        // add frequency with index based on mod - this ensures that we calcluate frequency, but the value at index i is not lost
        // e.g. arr =  3 | 1 | 4 | 1 | 3
        // 3 + 0 x nz = 3 ==> freq of 0 is 0 + 3 stored here
        // 1 + 2 x nz = 2nz + 1 ==> freq of 1 is 2 + 1 stored here
        // and so on
        // then the lowest missing will be that which has 0 when the value is divided by nz ==> this implies only value here is < nz thus freuqncy added 0
        for (int i = 0; i < nz; i++) {
            if ((nums[i] % nz) != 0) nums[nums[i] % nz] += nz;
        }

        for (int i = 1; i < nz; i++) {
            if ((nums[i] / nz) == 0) return i;
        }

        return nz + (hasN ? 1 : 0);
    }
};
