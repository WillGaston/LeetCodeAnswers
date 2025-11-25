class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // let dp[i] be a vector of valid strings starting at i and ending at sz
        // for each valid word starting at i ending at j we try to prepend it to each valid word starting at j + 1 ending at sz

        int sz = s.size();
        map<int, vector<string>> dp; // map of words starting at i ending at end of string

        for (int i = sz - 1; i >= 0; i--) {
            vector<string> possibleWords;
            for (int j = i; j < sz; j++) {
                string currWord = s.substr(i, j - i + 1);

                for (string w : wordDict) {
                    if (w == currWord) {
                        // check if we are at the end of the string
                        if (j == sz - 1) {
                            possibleWords.push_back(currWord);
                        } 
                        // append the current string to each other string starting from the next index
                        else {
                            vector<string> appendWords = dp[j + 1];
                            for (string word : appendWords) {
                                possibleWords.push_back(currWord + " " + word);
                            }
                        }
                    }
                }
            }

            dp[i] = possibleWords;
        }

        return dp[0];
    }
};
