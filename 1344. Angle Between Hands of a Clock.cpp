class Solution {
public:
    double angleClock(int hour, int minutes) {
        double mDeg = 360 * (1.0 * minutes / 60);
        double hDeg = 360 * ((1.0 * hour / 12) + (1.0 * minutes / (12 * 60)));
        double diff = abs(hDeg - mDeg);
        return min(diff, 360 - diff);
    }
};
