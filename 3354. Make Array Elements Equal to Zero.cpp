class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        // we repeatedly reverse directions like a pinball.
        // we need to see if there is a point where the sum of nums left and right are equal or differs by 1 and current element is 0
        // - if there is not, return 0
        // - if there is, add to numSols
        // O(2n)

        int runningSum1 = 0;
        int runningSum2 = 0;
        int n = nums.size();
        int numSol = 0;

        for (int num : nums) {
            runningSum1 += num;
        }

        for (int num : nums) {
            runningSum2 += num;
            if (num != 0) continue;
            if (runningSum2 == runningSum1 - runningSum2) numSol += 2;
            else if (abs(runningSum1 - 2*(runningSum2)) == 1) numSol++;
        }

        return numSol;
    }
};
