class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // pure simulation
        int index;
        int globalXor = 0;
        long mod = 1000000007;

        for (vector<int> q : queries) {
            int k = q[2];
            int r = q[1];
            int v = q[3];
            index = q[0];
            for (index; index <= r; index += k) {
                nums[index] = ((1LL * nums[index] * v) % (mod));
            }
        }

        for (int num : nums) globalXor ^= num;

        return globalXor;
    }
};
