class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> chars;

        for (int num : nums) {
            chars.push_back(to_string(num));
        }

        sort(chars.begin(), chars.end(), [](string& a, string&b) { return a + b > b + a; });

        if (chars[0] == "0") return "0";

        string output = "";

        for (string c : chars) {
            output += c;
        }

        return output;
    }
};
