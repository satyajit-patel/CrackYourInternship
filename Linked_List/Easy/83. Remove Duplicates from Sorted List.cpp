/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void add(int it, ListNode*& head, ListNode*& tail) {
        if(!head) {
            ListNode* newNode = new ListNode(it);
            tail = newNode;
            head = newNode;
            return;
        }

        ListNode* newNode = new ListNode(it);
        tail->next = newNode;
        tail = newNode;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        set<int> st;
        while(head) {
            st.insert(head->val);
            head = head->next;
        }

        ListNode* tail = NULL;
        for(auto& it: st) {
            add(it, head, tail);
        }

        return head;
    }
};