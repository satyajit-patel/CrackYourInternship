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
    ListNode* newHead;
    ListNode* newTail;

    void add(int val) {
        if(!newHead) {
            ListNode* newNode = new ListNode(val);
            newHead = newNode;
            newTail = newNode;
            return;
        }
        ListNode* newNode = new ListNode(val);
        newTail->next = newNode;
        newTail = newNode;
    }

    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        std::vector<int> v1, v2;
        while(temp) {
            if(temp->val < x) v1.push_back(temp->val);
            else v2.push_back(temp->val);
            temp = temp->next;
        }
        std::vector<int> ans;
        for(auto& it:v1) ans.push_back(it);
        for(auto& it:v2) ans.push_back(it);

        newHead = NULL;
        newTail = NULL;
        for(auto& it:ans) add(it);
        return newHead;
    }
};