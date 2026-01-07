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
    int maxProduct(TreeNode* root) {
        long long totalSum = 0;
        computeTotalSum(root, totalSum);
        long long maxProduct = 0;
        computeMaxProduct(root, maxProduct, totalSum);
        return maxProduct % 1000000007;
    }

    void computeTotalSum(TreeNode* root, long long& totalSum) {
        if (root) totalSum += root->val;
        if (root->left) computeTotalSum(root->left, totalSum);
        if (root->right) computeTotalSum(root->right, totalSum);
    }

    long long computeMaxProduct(TreeNode* root, long long& maxProduct, long long totalSum) {
        if (!root) return 0;

        long long currSum = computeMaxProduct(root->left, maxProduct, totalSum) + computeMaxProduct(root->right, maxProduct, totalSum) + root->val;
        if ((totalSum - currSum) * currSum > maxProduct) maxProduct = (totalSum - currSum) * currSum;
        return currSum;
    }
};
