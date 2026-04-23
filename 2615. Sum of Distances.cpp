class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int nz = nums.size();
        vector<long long> arr(nz, 0);

        // arr[i] = sum of i - j for all j such that nums[j] == nums[i]
        // use map to get indices of same elements, iterate over that

        // can use prefixSum to speed up computation.
        // consider the index i with valToIndex[i] = [2,5,7,10] and prefSum = [2,7,14,24]
        // assume index i = 5, index in index array = 1;
        // then = (5-2) + (5-7) + (5-10) = (5-2) + (7-5) + (10-5)
        // before 1 ==> 1 x 5 - (prefSum[1] - 5)
        // after 2 ==> (prefSum[end] - prefSum[index]) - (index x 5)
        // - this gives O(n) amortized as we prefix sum compute only the actual vals, not looping for each

        map<int, vector<int>> valToInd;

        for (int i = 0; i < nz; i++) {
            valToInd[nums[i]].push_back(i);
        }

        for (auto& [index, inds] : valToInd) {
            long long runningSum = 0;
            vector<long long> prefSum;
            for (int num : inds) { runningSum += num; prefSum.push_back(runningSum); }
            int indsz = inds.size();

            for (int i = 0; i < indsz; i++) {
                // perform our computation
                int indVal = inds[i];
                arr[inds[i]] = ((1LL * i * indVal) - (prefSum[i] - indVal)) + (prefSum[indsz - 1] - prefSum[i]) - (1LL * indVal * (indsz - i - 1));
            }
        }

        return arr;
    }
};
