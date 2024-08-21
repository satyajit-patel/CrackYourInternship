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

    ListNode* sortList(ListNode* head) {
        vector<int> ans;
        while(head) {
            // cout<<head->val<<" ->> ";
            ans.push_back(head->val);
            head = head->next;
        }
        std::sort(ans.begin(), ans.end());
        ListNode* tail = NULL;
        for(auto& it: ans) {
            add(it, head, tail);
        }
        return head;
    }
};