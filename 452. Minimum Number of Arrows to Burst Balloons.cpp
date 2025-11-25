class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        } else {
            return a[1] < b[1];
        }
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        // ballons with diameter defined by [points[i][0], points[i][1]] == [start, end]
        // want to find minimum number of points such that all balloons are included

        // sort by start time then by end time
        // greedy heuristic: always choose the leftmost finish time --> all unpopped ballons with a smaller start time can be popped

        sort(points.begin(), points.end(), comparator);

        int currPoint = points[0][1];
        int numArrows = 1;
        int idx = 0;
        int pz = points.size();

        while(idx < pz) {
            if (points[idx][0] <= currPoint) {
                idx++;
            } else {
                numArrows++;
                currPoint = points[idx][1];
            }
        }

        return numArrows;
    }
};
