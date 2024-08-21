// https://www.geeksforgeeks.org/problems/reorder-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    Node* reverse(Node* head) {
        if (head == nullptr) {
            return head;
        }
        
        Node* prev = nullptr;
        Node* h = head;
        
        while (h != nullptr) {
            Node* temp = h->next;
            h->next = prev;
            prev = h;
            h = temp;
        }
        return prev;
    }
    
    Node* reorderList(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        Node* slow = head;
        Node* fast = head;
        Node* prevSlow = nullptr;
        
        while (fast != nullptr && fast->next != nullptr) {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* reverseHead = reverse(slow);
        prevSlow->next = nullptr;
        
        fast = head;
        slow = reverseHead;
        
        while (fast != nullptr) {
            Node* tempFast = fast->next;
            Node* tempSlow = slow->next;
            fast->next = slow;
            if (tempSlow != nullptr && tempFast != nullptr) {
                slow->next = tempFast;
            }
            fast = tempFast;
            slow = tempSlow;
        }
        
        return head;
    }
};