// https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
/*
struct Node {
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

void add(int val, Node*& head, Node*& tail) {
    if(!head) {
        Node* newNode = new Node(val);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(val);
    tail->next = newNode;
    tail = newNode;
}

class Solution {
public:
    Node* divide(Node* head) {
        vector<int> even, odd;
        while(head) {
            int x = head->data;
            if(x & 1) {
                odd.push_back(x);
            } else {
                even.push_back(x);
            }
            head = head->next;
        }
        Node* tail = NULL;
        for(auto& it: even) {
            add(it, head, tail);
        }
        for(auto& it: odd) {
            add(it, head, tail);
        }
        return head;
    }
};
