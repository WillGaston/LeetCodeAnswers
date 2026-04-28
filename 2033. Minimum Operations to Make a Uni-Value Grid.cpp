class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flattened;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                flattened.push_back(grid[i][j]);
            }
        }

        sort(flattened.begin(), flattened.end());

        int numOps = 0;
        int midVal = flattened[flattened.size() / 2];

        for (int number : flattened) {
            if ((number % x != midVal % x)) return -1;
            numOps += (abs(midVal - number) / x);
        }

        return numOps;
    }
};
