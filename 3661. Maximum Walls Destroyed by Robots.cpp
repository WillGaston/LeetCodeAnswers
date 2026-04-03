class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        // endless straight line which has robots and walls
        // - robots can fire gun and destroy walls but travel distance is constrained
        // - bullet cannot travel through robot
        // - bullet distance is min(distance to next robot, distance of bullet)
        // let dp[i][j] be the maximum walls destroyed after robot i, where the ith shot l or r

        int nr = robots.size();
        
        // 0 = l, 1 = r
        vector<vector<int>> dp(nr, vector<int>(2, 0));
        vector<vector<int>> robDist;

        for (int i = 0; i < nr; i++) {
            robDist.push_back({robots[i], distance[i]});
        }

        sort(robDist.begin(), robDist.end(), [](const auto& a, const auto& b) {return a[0] < b[0];});
        sort(walls.begin(), walls.end());

        dp[0][0] = wallsInRange(robDist[0][0] - robDist[0][1], robDist[0][0] + 1, walls);
        if (nr > 1) dp[0][1] = wallsInRange(robDist[0][0], min(robDist[0][0] + robDist[0][1] + 1, robDist[1][0]), walls);
        else dp[0][1] = wallsInRange(robDist[0][0], robDist[0][0] + robDist[0][1] + 1, walls);

        for (int i = 1; i < nr; i++) {
            int wallsWithLeftBoundFiredRight = wallsInRange(max(robDist[i - 1][0] + 1, robDist[i][0] - robDist[i][1]), robDist[i][0] + 1, walls);
            int wallsWithLeftBound = wallsInRange(max(robDist[i - 1][0] + 1, robDist[i][0] - robDist[i][1]), robDist[i][0] + 1, walls);
            int overlapWalls = wallsInRange(max(robDist[i - 1][0] + 1, robDist[i][0] - robDist[i][1]), min(robDist[i - 1][0] + robDist[i - 1][1] + 1, robDist[i][0]), walls);
            int wallsWithRightBound;
            if (i + 1 < nr) wallsWithRightBound = wallsInRange(robDist[i][0], min(robDist[i][0] + robDist[i][1] + 1, robDist[i + 1][0]), walls);
            else wallsWithRightBound = wallsInRange(robDist[i][0], robDist[i][0] + robDist[i][1] + 1, walls);

            dp[i][0] = max(dp[i - 1][0] + wallsWithLeftBound, dp[i - 1][1] + wallsWithLeftBoundFiredRight - overlapWalls);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + wallsWithRightBound;
        }
    
        return max(dp[nr - 1][0], dp[nr - 1][1]);
    }

    int wallsInRange(int low, int high, vector<int>& walls) {
        int index = getMinBoundIndex(low, walls);
        if (index == -1) return 0;
        int num = 0;

        for (int i = index; i < (int)walls.size() && walls[i] < high; i++) {
            num++;
        }

        return num;
    }

    int getMinBoundIndex(int low, vector<int>& walls) {
        int lo = 0;
        int hi = walls.size() - 1;
        int ind = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int currInd = walls[mid];
            if (currInd < low) {
                lo = mid + 1;
            } else if (currInd >= low) {
                ind = mid;
                hi = mid - 1; 
            }
        }

        return ind;
    }
};
