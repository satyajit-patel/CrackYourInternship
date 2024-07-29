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
    void state(TreeNode* root, int& mini, TreeNode*& prev) {
        // base case
        if(!root) {
            return;
        }

        // transition
        state(root->left, mini, prev);
        if(prev) {
            mini = std::min(mini, root->val - prev->val);
        }
        prev = root;
        state(root->right, mini, prev);

    }

    int getMinimumDifference(TreeNode* root) {
        int mini = INT_MAX;
        TreeNode* prev = NULL;
        state(root, mini, prev);
        return mini;
    }
};