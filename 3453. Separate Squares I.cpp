class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double largestY = 0.0;

        for (const vector<int>& sq : squares) {
            totalArea += double(sq[2]) * sq[2];
            largestY = max(largestY, double(sq[1] + sq[2]));
        }

        double hi = largestY;
        double lo = 0.0;

        while (hi - lo > 1e-5) {
            double mid = (lo + hi) / 2;
            if (checkIsGreater(mid, squares, totalArea)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return hi;
    }

    bool checkIsGreater(double largestY, vector<vector<int>>& squares, double totalArea) {
        double area = 0.0;

        for (const vector<int>& sq : squares) {
            double currY = sq[1];
            if (currY < largestY) { 
                area += sq[2] * min(double(sq[2]), largestY - currY);
            }
        }

        return area >= totalArea / 2.0;
    }
};
