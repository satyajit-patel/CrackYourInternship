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
    void state(TreeNode* root, string temp, vector<string>& ans) {
        // base case
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            temp += std::to_string(root->val);
            ans.push_back(temp);
            return;
        }

        // transition
        state(root->left, temp + std::to_string(root->val) + "->", ans);
        state(root->right, temp + std::to_string(root->val) + "->", ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        state(root, "", ans);
        return ans;
    }
};