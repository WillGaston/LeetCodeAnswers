class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        // circular array nums
        // for each query
        //  - find min dist from queries[i] and any other number such that nums[queries[i]] == nums[j]

        // just use a map for same values with indices, keep it sorted
        // compare closest index either next or prev index, or if at end, wrap around

        vector<int> results;
        map<int, vector<int>> m;
        int nz = nums.size();

        for (int i = 0; i < nz; i++) {
            m[nums[i]].push_back(i + 1);
        }

        for (int queryIndex : queries) {
            int val = nums[queryIndex];
            queryIndex++;
            int prev = -1;
            int next = -1;
            vector<int>& indVector = m[val];
            int ivz = indVector.size();

            auto it = lower_bound(indVector.begin(), indVector.end(), queryIndex);
            int i = distance(indVector.begin(), it);

            if (i < ivz - 1) next = indVector[i + 1];
            if (i > 0) prev = indVector[i - 1];

            if (prev == -1 && next == -1) {
                results.push_back(-1);
            } else if (prev == -1) { // need to check next and prev wrap
                int prevDist = (nz - indVector[ivz - 1]) + queryIndex;
                int nextDist = next - queryIndex;
                results.push_back(min(prevDist, nextDist));
            } else if (next == -1) {
                int prevDist = queryIndex - prev;
                int nextDist = (nz - queryIndex) + indVector[0];
                results.push_back(min(prevDist, nextDist)); 
            } else {
                int prevDist = queryIndex - prev;
                int nextDist = next - queryIndex;
                results.push_back(min(prevDist, nextDist)); 
            }
        }

        return results;
    }
};
