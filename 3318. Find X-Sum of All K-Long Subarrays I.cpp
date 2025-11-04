class Solution {
public:
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        return (a.second == b.second) ? a.first > b.first : a.second > b.second;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> subArrs;

        for (int i = 0; i <= nums.size() - k; i++) {
            map<int, int> m;
            int currSum = 0 ;

            for (int j = i; j < i + k; j++) {
                m[nums[j]]++;
            }

            vector<pair<int, int>> fq(m.begin(), m.end());
            sort(fq.begin(), fq.end(), comp);

            int ind = min(x, (int)fq.size());

            for (auto vals : fq) {
                currSum += vals.first * vals.second;
                ind--;
                if (ind <= 0) break;
            }

            subArrs.push_back(currSum);
        }

        return subArrs;
    }
};
