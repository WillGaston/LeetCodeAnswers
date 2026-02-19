class Solution {
public:
    int countBinarySubstrings(string s) {
        int num = 0;
        int prev = 0;
        int curr = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) {
                // we have found the end of a group, add the sum current
                num += min(prev, curr);
                prev = curr;
                curr = 1;
            } else {
                curr++;
            }
        }

        num += min(prev, curr);

        return num;
    }
};
