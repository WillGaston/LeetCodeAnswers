class Solution {
public:
    static bool compara(vector<int>& a, vector<int>&b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // we want to keep the maximum amount of time remianing for other intervals
        // - include the next interval which finishes first and starts after the current endpoint

        sort(intervals.begin(), intervals.end(), compara);
        int total = 1;
        int prev = 0;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= intervals[prev][1]) {
                total++;
                prev = i;
            }
        }

        return intervals.size() - total;
    }
};
