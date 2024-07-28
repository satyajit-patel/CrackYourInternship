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
    void state(TreeNode* root, int& sum, int isLeftLeaf) {
        // base case
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            if(isLeftLeaf) {
                sum += root->val;
            }
            return;
        }

        // transition
        state(root->left, sum, 1);
        state(root->right, sum, 0);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        state(root, sum, 0);
        return sum;
    }
};