class Solution {
public:
    string getHappyString(int n, int k) {
        n1 = n;

        vector<string> result;
        recurse("a", &result);
        recurse("b", &result);
        recurse("c", &result);

        if (k > result.size()) return "";
        return result[k - 1];
    }

    void recurse(string curr, vector<string> *result) {
        if (curr.size() == n1) {
            (*result).push_back(curr);
            return;
        }

        char prev = curr[curr.size() - 1];
        if (prev == 'a') {
            recurse(curr + "b", result);
            recurse(curr + "c", result);
        } else if (prev == 'b') {
            recurse(curr + "a", result);
            recurse(curr + "c", result);
        } else {
            recurse(curr + "a", result);
            recurse(curr + "b", result);
        }
    }

private:
    int n1;
};
