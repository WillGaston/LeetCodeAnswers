class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        // think about each column as a histogram
        // dp[i][j] is the length of a sequence of 1s ending at j for column i
        int largest = 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) dp[i][j]  = 0;
                else {
                    if ((i - 1) >= 0) dp[i][j] = dp[i - 1][j] + 1;
                    else dp[i][j] = 1;
                }
            }
        }

        // for each row sort by value and try to construct a submatrix with this as the bottom
        //cout << "blah" << endl;


        for (int i = 0; i < m; i++) {
            vector<int> currentRow = dp[i];

            sort(currentRow.begin(), currentRow.end(), greater());

            //cout << currentRow.size() << '\n' << endl; 
            //for (int j = 0; j < n; j++) {
            //    cout << currentRow[j] << endl;
            //}

            //cout << largest;

            //cout << endl;

            for (int j = 0; j < n; j++) {
                largest = max(largest, currentRow[j] * (j + 1));
            }
        }

        return largest;
    }
};
