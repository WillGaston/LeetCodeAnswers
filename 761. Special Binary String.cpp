class Solution {
public:
    string makeLargestSpecial(string s) {
        // we want to swap consecutive 1s and 0s
        // we want to ensure the prefix condition is maintained
        // - we only swap when the current 'height' is 0 - this ensures we do not accidentally break the condition
        // - to rearrange we just swap the outer two items and continue processing the inner items
        //   - this works because we know what we are recursing on is even and will eventually be able to change to having all 1s then 0s

        int height = 0;
        vector<string> balancedChunks;
        string output = "";
        int startPoint = 0;
        int sz = s.size();

        for (int i = 0; i < sz; i++) {
            if (s[i] == '1') height++;
            else height--;

            // if we know start -> height is balanced, we can rearrange 
            if (height == 0) {
                string innerString = makeLargestSpecial(s.substr(startPoint + 1, i - startPoint - 1));
                balancedChunks.push_back("1" + innerString + "0");
                startPoint = i + 1;
            }
        }

        sort(balancedChunks.begin(), balancedChunks.end(), [](string &a ,string &b) { return a > b; });
        for (const string &st : balancedChunks) output += st;

        return output;
    }
};
