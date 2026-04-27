class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        if (grid.size() == 1 && grid[0].size() == 1) return true;
        int gridVal = grid[0][0];
        grid[0][0] = 0;

        if (gridVal == 1 || gridVal == 6) return bfs(0, 1, 1, grid);
        else if (gridVal == 2 || gridVal == 3) return bfs(1, 0, 2, grid);
        else if (gridVal == 4) return bfs(0, 1, 1, grid) || bfs(1, 0, 2, grid);
        else return false;
    }

    bool bfs(int i, int j, int dir, vector<vector<int>>& grid) { // dir tells us which part of the square we enter from
        // 1 = left
        // 2 = up
        // 3 = right
        // 4 = down

        if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size()) return false;
        if (i == (int)grid.size() - 1 && j == (int)grid[0].size() - 1) {
            int gridValCheck = grid[i][j];
            if (dir == 1) return gridValCheck == 1 || gridValCheck == 3 || gridValCheck == 5;
            else if (dir == 2) return gridValCheck == 2 || gridValCheck == 5 || gridValCheck == 6;
            else if (dir == 3) return gridValCheck == 1 || gridValCheck == 4 || gridValCheck == 6;
            else if (dir == 4) return gridValCheck == 2 || gridValCheck == 3 || gridValCheck == 4;
            return false;
        }

        int gridVal = grid[i][j];
        grid[i][j] = 0;
        bool result = false;

        if (dir == 1) {
            if (gridVal == 1) result = bfs(i, j + 1, 1, grid);
            else if (gridVal == 3) result = bfs(i + 1, j, 2, grid);
            else if (gridVal == 5) result = bfs(i - 1, j, 4, grid);
        } else if (dir == 2) {
            if (gridVal == 2) result = bfs(i + 1, j, 2, grid);
            else if (gridVal == 5) result = bfs(i, j - 1, 3, grid);
            else if (gridVal == 6) result = bfs(i, j + 1, 1, grid);
        } else if (dir == 3) {
            if (gridVal == 1) result = bfs(i, j - 1, 3, grid);
            else if (gridVal == 4) result = bfs(i + 1, j, 2, grid);
            else if (gridVal == 6) result = bfs(i - 1, j, 4, grid);
        } else if (dir == 4) {
            if (gridVal == 2) result = bfs(i - 1, j, 4, grid);
            else if (gridVal == 3) result = bfs(i, j - 1, 3, grid);
            else if (gridVal == 4) result = bfs(i, j + 1, 1, grid);
        }

        return result;
    }
};
