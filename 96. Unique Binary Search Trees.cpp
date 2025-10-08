class Solution {
public:
    int numTrees(int n) {
        // subproblem: dp[i] is the number of bst's we can create with i nodes
        // idea: if we have n nodes left, we can fix any of these as the root, each node will have a unique number of nodes in the
        //       left and right subtree (e.g. fixing 2 as root, gives us just 1 on left subtree (size 1) and 3,4,5 on right subtree
        //       (size 3), fixing one gives nothing on left (size 0) and 2,3,4,5 on right (size 4))
        //       We need to sum all of these arrangements to get the total number for n = 5.
        // relation: sum(dp[curr - i - 1] + dp[i]) for i = [0, n - 1]
        // base cases: dp[0] = 1; dp[1] = 1
        // order of computation: increasing order of i
        // time complexity: for each n, we need to loop across at most n other entries to get the sum, so O(n^2)

        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            int sum = 0;
            for (int j = 0; j < i; j++) {
                sum += dp[i - j - 1] * dp[j];
            }
            dp[i] = sum;
        }

        return dp[n];
    }
};
