class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        // let xdp[i][j] be the number of xs in a submatrix ending at x, y
        // similar for ydp
        // if xdp == ydp then increment

        int m = grid.size();
        int n = grid[0].size();
        int num = 0;
        vector<vector<int>> xdp(m, vector<int>(n, 0));
        vector<vector<int>> ydp(m, vector<int>(n, 0));

        xdp[0][0] = ((grid[0][0] == 'X') ? 1 : 0);
        ydp[0][0] = ((grid[0][0] == 'Y') ? 1 : 0);

        for (int i = 1; i < m; i++) {
            xdp[i][0] = xdp[i - 1][0] + ((grid[i][0] == 'X') ? 1 : 0);
            ydp[i][0] = ydp[i - 1][0] + ((grid[i][0] == 'Y') ? 1 : 0);

            if (xdp[i][0] && (xdp[i][0] == ydp[i][0])) num++;
        }

        for (int i = 1; i < n; i++) {
            xdp[0][i] = xdp[0][i - 1] + ((grid[0][i] == 'X') ? 1 : 0);
            ydp[0][i] = ydp[0][i - 1] + ((grid[0][i] == 'Y') ? 1 : 0);

            if (xdp[0][i] && (xdp[0][i] == ydp[0][i])) num++;
        }

        //cout << xdp[0][0] << endl;
        //cout << ydp[0][0] << endl;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                xdp[i][j] = xdp[i - 1][j] + xdp[i][j - 1] - xdp[i - 1][j - 1];
                ydp[i][j] = ydp[i - 1][j] + ydp[i][j - 1] - ydp[i - 1][j - 1];
                if (grid[i][j] == 'X') xdp[i][j]++;
                else if (grid[i][j] == 'Y') ydp[i][j]++;

                if (xdp[i][j] != 0 && (xdp[i][j] == ydp[i][j])) num++;
            }
        }

        return num;
    }
};
