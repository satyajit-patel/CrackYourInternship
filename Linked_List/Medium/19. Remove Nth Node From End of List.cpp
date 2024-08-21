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
    void add(int val, ListNode*& head, ListNode*& tail) {
        if(!head) {
            ListNode* newNode = new ListNode(val);
            head = newNode;
            tail = newNode;
            return;
        }
        ListNode* newNode = new ListNode(val);
        tail->next = newNode;
        tail = newNode;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tail = head;
        vector<int> a;
        while(tail) {
            a.push_back(tail->val);
            tail = tail->next;
        }
        std::reverse(a.begin(), a.end());
        a.erase(a.begin()+(n-1));
        std::reverse(a.begin(), a.end());
        head = NULL;
        tail = NULL;
        for(auto& it: a) {
            add(it, head, tail);
        }
        return head;
    }
};