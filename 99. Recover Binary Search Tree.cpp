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
    void recoverTree(TreeNode* root) {
        vector<int> serialization;
        inOrderTrav(root, serialization);
        sort(serialization.begin(), serialization.end());
        int i = 0;
        checkSerialization(root, serialization, i);
    }

    void inOrderTrav(TreeNode* root, vector<int>& serialization) {
        if (!root) return;
        inOrderTrav(root->left, serialization);
        serialization.push_back(root->val);
        inOrderTrav(root->right, serialization);
    }

    void checkSerialization(TreeNode* root, vector<int>& serialization, int& i) {
        if (!root) return;
        checkSerialization(root->left, serialization, i);
        if (serialization[i] != root->val) {
            int temp = root->val;
            root->val = serialization[i];
            serialization[i] = temp;
            
        }
        i++;
        checkSerialization(root->right, serialization, i);
    }
};
