class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();

        int maxTime = m * m - 1;
        int minTime = 0;

        int currTime = maxTime;

        while (minTime <= maxTime) {
            int midTime = (maxTime + minTime) / 2;
            if (bfs(midTime, grid, m)) {
                maxTime = midTime - 1;
                currTime = midTime;
            } else {
                minTime = midTime + 1;
            }
        }

        return currTime;
    }

    bool bfs(int maxDepth, vector<vector<int>>& grid, int m) {
        if (grid[0][0] > maxDepth) return false;

        queue<vector<int>> q;
        vector<vector<bool>> visited(m, vector<bool>(m, false));

        // up, down, left, right
        vector<int> diffX = {0, 0, -1, 1};
        vector<int> diffY = {-1, 1, 0, 0};

        q.push({0, 0});
        visited[0][0] = true;

        while (q.size() > 0) {
            vector<int> currPoint = q.front();
            q.pop();
            int x = currPoint[0];
            int y = currPoint[1];

            for (int i = 0; i < 4; i++) {
                int otherX = x + diffX[i];
                int otherY = y + diffY[i];

                if (otherX < 0 || otherX >= m || otherY < 0 || otherY >= m) continue;
                if (visited[otherX][otherY] || grid[otherX][otherY] > maxDepth) continue;

                q.push({otherX, otherY});
                visited[otherX][otherY] = true;
            }
        }

        return visited[m - 1][m - 1];
    }
};
