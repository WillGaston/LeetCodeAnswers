class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int longest = 0;
        int r = 0;
        int wz = word.size();

        for (int l = 0; l < wz; l++) {
            if (word[l] == 'a') {
                r = l;
                char prev = 'a';
                set<char> seen = {'a'};
                while (r < wz) {
                    if ((prev == 'a' && (word[r] == 'a' || word[r] == 'e')) ||
                        (prev == 'e' && (word[r] == 'e' || word[r] == 'i')) ||
                        (prev == 'i' && (word[r] == 'i' || word[r] == 'o')) ||
                        (prev == 'o' && (word[r] == 'o' || word[r] == 'u')) ||
                        (prev == 'u' && word[r] == 'u')
                    ) {
                        prev = word[r];
                        seen.insert(prev);
                        r++;
                    } else {
                        break;
                    }
                } 
                if (seen.size() == 5) longest = max(longest, r - l);
                l = r - 1;
            }
        }

        return longest;
    }
};
