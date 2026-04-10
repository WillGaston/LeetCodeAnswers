class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> m; // num val to index
        int nz = nums.size();
        int dist = INT_MAX;

        for (int i = 0; i < nz; i++) {
            m[nums[i]].push_back(i);
        }

        for (const auto& [a, b] : m) {
            for (int i = 0; i < b.size(); i++) {
                for (int j = i + 1; j < b.size(); j++) {
                    for (int k = j + 1; k < b.size(); k++) {
                        //cout << i << " " << j << " " << k << endl;
                        int ii = b[i];
                        int jj = b[j];
                        int kk = b[k];
                        dist = min(dist, abs(ii - jj) + abs(jj - kk) + abs(kk - ii));
                    }
                }
            }
        }

        return (dist == INT_MAX) ? -1 : dist;
    }
};
