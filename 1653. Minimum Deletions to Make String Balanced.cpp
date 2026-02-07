class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> prefA;
        vector<int> prefB;
        int totA = 0;
        int totB = 0;

        int sz = s.size();

        for (char c : s) {
            if (c == 'a') {
                totA++;
            } else {
                totB++;
            }
            prefA.push_back(totA);
            prefB.push_back(totB);
        }

        if (totA == 0 || totB == 0) return 0;

        // want to find point where prefB and totA - prefA is minimal ==> this is the answer;

        int ans = totA;

        for (int i = 0; i < sz; i++) {
            ans = min(ans, prefB[i] + totA - prefA[i]);
        }

        return ans;
    }
};
