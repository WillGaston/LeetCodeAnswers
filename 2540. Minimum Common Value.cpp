class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = 0;
        int n2 = 0;
        int nz1 = nums1.size();
        int nz2 = nums2.size();

        while (n1 < nz1 && n2 < nz2) {
            int n1i = nums1[n1];
            int n2i = nums2[n2];
            if (n1i == n2i) return n1i;
            if (n1i > n2i) n2++;
            else n1++;
        }

        if (n1 >= nz1 && n2 >= nz2) return -1;

        if (n1 < nz1) {
            int n2i = nums2[n2 - 1];
            while (n1 < nz1) {
                if (nums1[n1] == n2i) return n2i;
                n1++;
            }
        } else if (n2 < nz2) {
            int n1i = nums1[n1 - 1];
            while (n2 < nz2) {
                if (nums2[n2] == n1i) return n1i;
                n2++;
            }
        }

        return -1;
    }
};
