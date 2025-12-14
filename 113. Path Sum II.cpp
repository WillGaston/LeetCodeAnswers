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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> output;
        vector<int> currPath;

        recurse(root, targetSum, 0, currPath, output);

        return output;
    }

    void recurse(TreeNode* root, int& targetSum, int currSum, vector<int> currPath, vector<vector<int>>& output) {
        if (root == NULL) return;

        currSum += root->val;
        currPath.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (targetSum == currSum) {
                output.push_back(currPath);
            }
            return;
        } else {
            recurse(root->left, targetSum, currSum, currPath, output);
            recurse(root->right, targetSum, currSum, currPath, output);
        }
    }
};
