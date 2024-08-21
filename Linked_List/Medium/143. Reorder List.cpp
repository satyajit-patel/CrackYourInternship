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
    void add(int val, ListNode*& newHead, ListNode*& newTail) {
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

    void reorderList(ListNode* head) {
        // head->next = NULL;

        vector<int> a;
        ListNode* temp = head;
        while(temp) {
            a.push_back(temp->val);
            temp = temp->next;    
        }

        vector<int> ans;
        bool flag = true;
        int i = 0;
        int j = a.size() - 1;
        while(i <= j) {
            if(flag) {
                ans.push_back(a[i]);
                i++;
                flag = false;
            } else {
                ans.push_back(a[j]);
                j--;
                flag = true;
            }
        }
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;
        ans.erase(ans.begin()+0); // jugad
        for(auto& it: ans) {
            add(it, newHead, newTail);
            // cout<<it<<" ";
        }
        // head = newHead;
        head->next = newHead;
        // head = head->next;
    }
};