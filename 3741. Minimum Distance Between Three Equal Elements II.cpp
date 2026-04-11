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
            for (int i = 2; i < b.size(); i++) {
                dist = min(dist, b[i] - b[i - 2]);
            }
        }

        return (dist == INT_MAX) ? -1 : 2 * dist;
    }
};
