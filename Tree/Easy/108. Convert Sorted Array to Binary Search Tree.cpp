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
    TreeNode* state(int i, int j, vector<int>& nums) {
        // base case
        if(i > j) {
            return NULL;
        }

        // transition
        int mid = (i + j) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = state(i, mid-1, nums);
        root->right = state(mid+1, j, nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ans = state(0, nums.size()-1, nums);
        return ans;
    }
};