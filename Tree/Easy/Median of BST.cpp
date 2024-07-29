// https://www.geeksforgeeks.org/problems/median-of-bst/1
/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

void state(Node* root, vector<int>& ans) {
    // base case
    if(!root) {
        return;
    }

    // transition
    state(root->left, ans);
    ans.push_back(root->data);
    state(root->right, ans);
}

float findMedian(struct Node *root){
    vector<int> in;
    state(root, in);
    
    int n = in.size();
    if(n & 1) {
        return in[n/2] * 1.0;
    }
    int i = n / 2;
    return (in[i] * 1.0 + in[i-1]) / 2;
}