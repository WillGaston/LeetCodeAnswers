class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size(); 
        vector<vector<char>> output(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            int prevEnder = n;
            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') prevEnder = j;
                if (boxGrid[i][j] == '#') {
                    int index = j;
                    int newEnder = j;
                    while (index + 1 < prevEnder) {
                        boxGrid[i][index] = '.';
                        boxGrid[i][index + 1] = '#';
                        newEnder = index + 1;
                        index++;
                    }
                    prevEnder = newEnder;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                output[j][i] = boxGrid[i][j];
            }
        }

        for (vector<char> &vec : output) reverse(vec.begin(), vec.end());

        return output;
    }
};
