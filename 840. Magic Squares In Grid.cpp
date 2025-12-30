class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 == 45. 45 / 3  == 15, so each column/row/diagonal must equal 15

        int num = 0;
        int colsz = grid.size();
        int rowsz = grid[0].size();

        for (int i = 0; i < colsz - 2; i++) {
            for (int j = 0; j < rowsz - 2; j++) {
                // i, j is the top left of our square
                if(checkIsMagic(i, j, grid)) num++;
            }
        }

        return num;
    }

    bool checkIsMagic(int i, int j, vector<vector<int>>& grid) {
        set<int> verify;

        if (grid[i + 1][j + 1] != 5) return false;

        for (int x = i; x < i + 3; x++) {
            for (int y = j; y < j + 3; y++) {
                if (grid[x][y] > 9 || grid[x][y] < 1) return false;
                verify.insert(grid[x][y]);
            }
        }

        if (verify.size() != 9) return false;

        int sum = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];

        if (sum != grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1]) return false;
        if (sum != grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2]) return false;
        if (sum != grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2]) return false;
        if (sum != grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2]) return false;
        if (sum != grid[i][j] + grid[i][j + 1] + grid[i][j + 2]) return false;
        if (sum != grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2]) return false;
        if (sum != grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j]) return false;

        return true;
    }
};
