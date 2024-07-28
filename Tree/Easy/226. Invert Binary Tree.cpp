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
    void state(TreeNode* root) {
        if(!root) {
            return;
        }

        // transition
        std::swap(root->left, root->right);
        state(root->left);
        state(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        state(root);
        return root;
    }
};