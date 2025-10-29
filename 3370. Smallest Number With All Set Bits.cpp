class Solution {
public:
    int smallestNumber(int n) {
        int allSet = 0;

        while (n > 0) {
            allSet <<= 1;
            allSet |= 1;
            n >>= 1;
        }

        cout << allSet;

        if (n == allSet) {
            allSet <<= 1;
            allSet |= 1;
        }

        return allSet;
    }
};
