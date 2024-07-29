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
    bool state(TreeNode* p, TreeNode* q) {
        // base case
        if(!p && !q) {
            return true;
        }
        if((!p && q) || (p && !q)) {
            return false;
        }
        if(p->val != q->val) {
            return false;
        }

        // transition
        if(!state(p->left, q->left)) {
            return false;
        }
        if(!state(p->right, q->right)) {
            return false;
        }
        return true;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = state(p, q);
        return ans;
    }
};