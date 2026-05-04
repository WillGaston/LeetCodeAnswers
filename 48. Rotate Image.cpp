class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // flipped over diagonal, the nrows reversed

        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j > i) continue;
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for (vector<int> &row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};
