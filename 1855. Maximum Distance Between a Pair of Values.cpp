class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // already sorted, so just use bin search + 2 pointers

        int maxDist = INT_MIN;
        int p1 = 0;
        int p2 = 0;

        for (int i = 0; i < nums1.size(); i++) {
            maxDist = max(maxDist, doBin(i, nums1[i], nums2));
        }


        return maxDist;
    }

    int doBin(int index, int val, vector<int>& nums2) {
        int lo = index;
        int hi = nums2.size();

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (val <= nums2[mid]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return max(0, lo - index - 1);
    }
};
