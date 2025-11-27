class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxElement = arrays[0][arrays[0].size() - 1];
        int minElement = arrays[0][0];

        int potMax = 0;
        
        for (vector<int> arr : arrays) {
            int currMax = arr[arr.size() - 1];
            int currMin = arr[0];

            potMax = max(potMax, abs(currMax - minElement));
            potMax = max(potMax, abs(maxElement - currMin));

            minElement = min(minElement, currMin);
            maxElement = max(maxElement, currMax);
        }

        return potMax;
    }
};
