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
    int state(TreeNode* root) {
        // base case 
        if(!root) {
            return 0;
        }

        // transition
        int left = state(root->left);
        int right = state(root->right);
        int ans = std::max(left, right) + 1;
        return ans;
    }

    int maxDepth(TreeNode* root) {
        int ans = state(root);
        return ans;
    }
};