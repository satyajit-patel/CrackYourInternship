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
    bool state(TreeNode* root, int target) {
        // base case
        if(!root) {
            return false;
        }
        if(!root->left && !root->right) {
            return target - root->val == 0;
        }

        // transition
        if(state(root->left, target - root->val)) {
            return true;
        }
        if(state(root->right, target - root->val)) {
            return true;
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = state(root, targetSum);
        return ans;
    }
};