class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> increasingFromHere;

        int runningSum = 1;
        increasingFromHere.push_back(1);
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                runningSum++;
            } else {
                runningSum = 1;
            }
            increasingFromHere.push_back(runningSum);
        }

        reverse(increasingFromHere.begin(), increasingFromHere.end());

        int lo = 0;
        int hi = nums.size();
        int maxValid = 0;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (checkIfValid(mid, increasingFromHere)) {
                maxValid = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return maxValid;
    }

    bool checkIfValid(int k, vector<int>& increasingFromHere) {
        for (int i = 0; (i + k) < (increasingFromHere.size()); i++) {
            if (increasingFromHere[i] >= k && increasingFromHere[i + k] >= k) return true;
        }
        return false;
    }
};
