// https://www.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1
class Solution{
public:
    void state(Node *root, int l, int h, int& sum) {
        // base case
        if(!root) {
            return;
        }
        
        // transition
        if(root->data >= l && root->data <= h) {
            // sum += root->data;
            sum++;
        }
        state(root->left, l, h, sum);
        state(root->right, l, h, sum);
    }

    int getCount(Node *root, int l, int h) {
        int sum = 0;
        state(root, l, h, sum);
        return sum;
    }
};