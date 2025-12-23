class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        map<vector<int>, int> used;
        vector<vector<int>> res;
        vector<int> current = {};
        recurse(nums, current, -1, used, res);
        return res;
    }

    void recurse(vector<int>& nums, vector<int> current, int i, map<vector<int>, int>& used, vector<vector<int>>& res) {
        if (used[current] <= 0) {
            res.push_back(current);
            used[current]++;
        }

        for (int j = i + 1; j < nums.size(); j++) {
            current.push_back(nums[j]);
            recurse(nums, current, j, used, res);
            current.pop_back();
        }
    }
};
