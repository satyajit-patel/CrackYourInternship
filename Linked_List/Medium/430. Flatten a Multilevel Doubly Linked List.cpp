/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        for(Node* temp=head; temp; temp=temp->next) {
            if(temp->child) {
                Node* next = temp->next;
                temp->next = temp->child;
                temp->next->prev = temp;
                temp->child = NULL;
                Node* p = temp->next;
                while(p->next) {
                    p = p->next;
                }
                p->next = next;
                if(next) {
                    next->prev = p;
                }
            }
        }
        return head;
    }
};