// 417. Pacific Atlantic Water Flow

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> output;

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> visitedAtl(m, vector<bool>(n, false));
        vector<vector<bool>> visitedPac(m, vector<bool>(n, false));

        oceanBFS(visitedAtl, heights, m, n, 0);
        oceanBFS(visitedPac, heights, m, n, 1);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visitedAtl[i][j] == true && visitedPac[i][j]) {
                    output.push_back({i, j});
                }
            }
        }

        return output;
    }

    // 0 == atl, 1 == pac
    void oceanBFS(vector<vector<bool>>& visited, vector<vector<int>>& heights, int m, int n, int type) {
        queue<pair<int, int>> q;

        if (type == 0) {
            for (int i = 0; i < n; i++) {
                q.push({m - 1, i});
                visited[m - 1][i] = true;
            }
            for (int j = 0; j < m; j++) {
                q.push({j, n - 1});
                visited[j][n - 1] = true;
            }
        } else {
            for (int i = 0; i < n; i++) {
                q.push({0, i});
                visited[0][i] = true;
            }
            for (int j = 0; j < m; j++) {
                q.push({j, 0});
                visited[j][0] = true;
            }
        }

        // left, right, up, down
        vector<int> diffX = {-1, 1, 0, 0};
        vector<int> diffY = {0, 0, -1, 1};

        while (q.size() > 0) {
            pair<int, int> point = q.front();
            q.pop();
            int x = point.first;
            int y = point.second;

            visited[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int otherX = x + diffX[i];
                int otherY = y + diffY[i];

                if (otherX < 0 || otherX >= m || otherY < 0 || otherY >= n) continue;
                if (visited[otherX][otherY]) continue;

                if (heights[otherX][otherY] >= heights[x][y]) q.push({otherX, otherY});
            }
        }   
    }
};
