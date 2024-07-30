/*
https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
public:
    void add(int val, Node*& head, Node*& tail) {
        if(!head) {
            Node* newNode = new Node(val);
            head = newNode;
            tail = newNode;
            return;
        }
        Node* newNode = new Node(val);
        tail->bottom = newNode; // observation
        tail = newNode;
    }

    Node *flatten(Node *root) {
        // cout<<root->next->bottom->data<<"->\n";
        vector<int> a;
        Node* P = root;
        while(P) {
            Node* Q = P;
            while(Q) {
                a.push_back(Q->data);
                Q = Q->bottom;
            }
            P = P->next;
        }
        
        Node* head = NULL;
        Node* tail = NULL;
        std::sort(a.begin(), a.end());
        for(auto& it: a) {
            // cout<<it<<"->";
            add(it, head, tail);
        }
        root = head;
        return root;
    }
};