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

    bool flag;
    int state(TreeNode* root) {
        // base case
        if(!root) {
            return 0;
        }

        // transition
        int left = state(root->left);
        int right = state(root->right);
        int ans = std::max(left, right) + 1;
        if(std::abs(left - right) > 1) {
            flag = false;
        }
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        flag = true;
        state(root);
        return flag;
    }
};