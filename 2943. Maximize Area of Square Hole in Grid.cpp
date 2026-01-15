class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int largestH = 0;
        int largestV = 0;

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int largestRunning = 0;

        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] - hBars[i - 1] > 1) {
                largestH = max(largestH, largestRunning);
                largestRunning = 0;
            } else {
                largestRunning++;
            }
        }

        largestH = max(largestH, largestRunning) + 2;
        largestRunning = 0;

        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] - vBars[i - 1] > 1) {
                largestV = max(largestV, largestRunning);
                largestRunning = 0;
            } else {
                largestRunning++;
            }
        }

        largestV = max(largestV, largestRunning) + 2;

        int minS = min(largestV, largestH);

        return minS * minS;

    }
};
