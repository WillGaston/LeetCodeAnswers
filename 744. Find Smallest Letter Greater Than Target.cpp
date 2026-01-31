class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0;
        int hi = letters.size() - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (target < letters[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return letters[lo % letters.size()];
    }
};
