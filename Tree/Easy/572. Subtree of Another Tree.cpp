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
    void state(TreeNode* root, vector<int>& v) {
        // base case
        if(!root) {
            v.push_back(1e9); // observation
            return;
        }

        // transition
        v.push_back(root->val);
        state(root->left, v);
        state(root->right, v);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> a, b;
        state(root, a);
        state(subRoot, b);

        for(int i=0; i<a.size(); i++) {
            vector<int> temp;
            for(int j=i; j<a.size(); j++) {
                temp.push_back(a[j]);
                if(temp == b) {
                    return true;
                }
            }
        }
        return false;
    }
};