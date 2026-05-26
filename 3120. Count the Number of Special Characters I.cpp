class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char, int> lm;
        map<char, int> um;

        set<char> spec;

        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                if (um[c] != 0) spec.insert(c);
                lm[c]++;
            } else {
                c += 'a' - 'A';
                if (lm[c] != 0) spec.insert(c);
                um[c]++;
            }
        }

        return spec.size();
    }
};
