class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // a binary code of length k means it includes k digits - thus 2^k values
        // use sliding window and add substrings to set - performing no other operations
        // at the end check the size of the set compared to 2^k

        unordered_set<string> st;
        int sz = s.size();

        for (int l = 0; l <= sz - k; l++) st.insert(s.substr(l, k));

        return st.size() == 1 << k;
    }
};
