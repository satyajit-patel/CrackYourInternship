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
    ListNode* new_head;
    ListNode* new_tail;

    void push_back(int val) {
        if(!new_head) {
            ListNode* new_node = new ListNode(val);
            new_head = new_node;
            new_tail = new_node;
            return;
        }
        ListNode* new_node = new ListNode(val);
        new_tail->next = new_node;
        new_tail = new_node;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> A;
        ListNode* P = head;
        while(P) {
            A.push_back(P->val);
            P = P->next;
        }
        left--;
        right--;
        while(left < right) {
            std::swap(A[left], A[right]);
            left++;
            right--;
        }
        new_head = NULL;
        new_tail = NULL;
        for(auto& it:A) push_back(it);
        return new_head;
    }
};