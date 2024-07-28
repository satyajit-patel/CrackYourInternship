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
    int state(TreeNode* root, int& maxi) {
        // base case
        if(!root) {
            return 0;
        }

        // transition
        int left = state(root->left, maxi);
        int right = state(root->right, maxi);

        maxi = std::max(maxi, left + right);
        return std::max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        state(root, maxi);
        return maxi;
    }
};