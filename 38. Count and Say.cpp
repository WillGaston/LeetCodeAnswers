class Solution {
public:
    string countAndSay(int n) {
        string currentString = "1";

        for (int i = 1; i < n; i++) {
            currentString = helper(currentString);
        }

        return currentString;
    }

    string helper(const string& str) {
        string temp = "";

        int i = 0;
        while (i < str.size()) {
            int j = i;
            int currAmount = 1;
            while (j < str.size() - 1 && str[j] == str[j + 1]) {
                currAmount++;
                j++;
            }

            temp += to_string(currAmount);
            temp += str[j];

            i = (j + 1);
        }

        return temp;
    }
};
