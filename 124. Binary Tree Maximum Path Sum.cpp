/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        // subproblem: let dp[i] be the maximum path sum with i as the root node. 
        // idea: is the maximum path will be either the maximum path in the right subtree, left subtree, or one or both or neither with
        //       the root
        // recurrence: dp[i] = max(dp[left] + val_i, dp[right] + val_i, val_i, dp[left] + dp[right] + val_i)
        //             where dp[i] = val_i
        // order of computation: leaves upwards - use recursion
        // time complexity: let n be the number of nodes, we need to perform the subproblem once for each node, each subproblem can be
        //                  completed in constant time, so O(n)

        int maxSum = INT_MIN;
        doRecurrence(root, maxSum);
        return maxSum;
    }

    int doRecurrence(TreeNode *root, int& maxSum) {
        int currVal = root->val;

        if (!root->left && !root->right) {
            maxSum = max(maxSum, currVal);
            return currVal;
        }

        int leftVal = -1000;
        int rightVal = -1000;

        if (root->left) {
            leftVal = doRecurrence(root->left, maxSum);
        }

        if (root->right) {
            rightVal = doRecurrence(root->right, maxSum);
        }

        maxSum = max(maxSum, leftVal + rightVal + currVal);
        maxSum = max(maxSum, currVal);
        maxSum = max(maxSum, max(leftVal + currVal, rightVal + currVal));

        return max(leftVal + currVal, max(currVal, rightVal + currVal));
    }
};
