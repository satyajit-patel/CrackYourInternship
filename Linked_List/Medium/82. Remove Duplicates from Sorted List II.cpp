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

    ListNode* deleteDuplicates(ListNode* head) {
        vector<int> nums;
        map<int, int> mp;
        while(head) {
            mp[head->val]++;
            nums.push_back(head->val);
            head = head->next;
        }
        vector<int> ans;
        for(auto& it: nums) {
            if(mp[it] == 1) {
                ans.push_back(it);
            }
        }
        ListNode* tail = NULL;
        for(auto& it: ans) {
            add(it, head, tail);
        }
        return head;
    }
};