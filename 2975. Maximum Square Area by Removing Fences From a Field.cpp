class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        // 1 .. m is a horizontal line inc. outline
        // 1 .. n is a vertical line inc outline

        int modNum = 1000000007;

        hFences.push_back(1);
        vFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        int largestPair = 0;
        unordered_set<int> vals;

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                vals.insert(hFences[j] - hFences[i]);
            }
        }

        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int val = vFences[j] - vFences[i];
                if (vals.contains(val)) largestPair = max(largestPair, val);
            }
        }

        long long area = (long long)largestPair * largestPair;
        area %= modNum;

        return area != 0 ? int(area) : -1;
    }
};
