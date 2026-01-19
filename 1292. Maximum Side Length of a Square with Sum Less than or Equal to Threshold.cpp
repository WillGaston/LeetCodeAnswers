class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int iz = mat.size();
        int jz = mat[0].size();

        vector<vector<int>> a(iz + 1, vector<int>(jz + 1, 0));

        for (int i = 1; i <= iz; i++) {
            for (int j = 1; j <= jz; j++) {
                a[i][j] = mat[i - 1][j - 1] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            }
        }

        int lo = 0;
        int hi = min(iz, jz);
        int val = 0;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            bool valid = false;
            // mid is our side length
            for (int i = mid; i <= iz; i++) {
                for (int j = mid; j <= jz; j++) {
                    if (a[i][j] - a[i - mid][j] - a[i][j - mid] + a[i - mid][j - mid] <= threshold) valid = true;
                }
            }
            if (valid) {
                val = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return val;
    }
};
