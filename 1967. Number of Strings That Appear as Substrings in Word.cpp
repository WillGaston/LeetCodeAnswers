class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int numIn = 0;
        //int wordsz = word.size();

        for (string pattern : patterns) {
            /* bool found = false;
            for (int i = 0; i < wordsz; i++) {
                if (compare(i, wordsz, pattern, word)) {
                    found = true;
                    break;
                }
            }
            if (found) numIn++; */
            if (word.find(pattern) != string::npos) numIn++;
        }

        return numIn;
    }

    /* bool compare(int start, int len, string str1, string str2) {
        for (int i = 0; i < str1.size(); i++) {
            if (i + start >= len) return false;
            if (str1[i] != str2[i + start]) return false;
        }

        return true;
    } */
};
