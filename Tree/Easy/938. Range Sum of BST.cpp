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
    void state(TreeNode* root, int low, int high,int& sum) {
        // base case
        if(!root) {
            return;
        }

        // transition
        if(root->val >= low && root->val <= high) {
            sum += root->val;
        }
        state(root->left, low, high, sum);
        state(root->right, low, high, sum);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        state(root, low, high, sum);
        return sum;
    }
};