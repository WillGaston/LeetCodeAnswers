class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // intervals - intervals[i] = {start, end} ==> same as newInterval
        // - sorted ascending by start

        // insert newInterval such that remains sorted ==> merging allowed

        // idea: 
        //  - find the leftmost start and rightmost end of intervals which overlap with newInterval
        //  - remove those intervals and insert a new interval with those bounds in the correct place
        // 
        // steps:
        //  - binary search to find start point, iterate until start of next interval is greater than current end
        //      - as we iterate remove those intervals which we come across
        //  - after iterating insert new interval and sort ==> either way will need at least n operations to shift in worst case.

        int NL = newInterval[0];
        int NR = newInterval[1];
        int is = intervals.size();
        int ip;

        vector<vector<int>> output;

        int left = 0;
        for (; left < is; left++) {
            if (intervals[left][1] >= NL) break;
        }

        // check if we add newInterval without any modification
        if (left == is || intervals[left][0] > NR) {
            intervals.insert(intervals.begin() + left, newInterval);
            return intervals;
        }

        ip = left;

        // left will be the start point of the iteration
        set<int> toRemove;
        int newStart = min(intervals[left][0], NL);
        int newEnd = max(intervals[left][1], NR);

        toRemove.insert(left);

        while (left < is && intervals[left][0] <= newEnd) {
            toRemove.insert(left);
            newStart = min(newStart, intervals[left][0]);
            newEnd = max(newEnd, intervals[left][1]);

            left++;
        }

        for (int i = 0; i < is; i++) {
            if (i == ip) output.push_back({newStart, newEnd});
            else if (toRemove.contains(i)) continue;
            else output.push_back(intervals[i]);
        }

        return output;
    }
};
