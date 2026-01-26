class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int minD = INT_MAX;

        sort(arr.begin(), arr.end());

        for (int i = 1; i < arr.size(); i++) {
            if (abs(arr[i] - arr[i - 1]) == minD) res.push_back({arr[i - 1], arr[i]});
            else if (abs(arr[i] - arr[i - 1]) < minD) {
                minD = abs(arr[i] - arr[i - 1]);
                while (res.size() > 0) res.pop_back();
                res.push_back({arr[i - 1], arr[i]});
            }
        }

        return res;
    }
};
