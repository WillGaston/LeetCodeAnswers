class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;

        for (int i = 1; i < points.size(); i++) {
            vector<int> curr = points[i];
            vector<int> prev = points[i - 1];
            time += max(abs(curr[0] - prev[0]), abs(curr[1] - prev[1]));
        }

        return time;
    }
};
