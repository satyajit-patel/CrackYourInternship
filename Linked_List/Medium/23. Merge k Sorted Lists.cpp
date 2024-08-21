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
    void add(int x, ListNode*& head, ListNode*& tail) {
        if(!head) {
            ListNode* newNode = new ListNode(x);
            head = newNode;
            tail = newNode;
            return;
        }
        ListNode* newNode = new ListNode(x);
        tail->next = newNode;
        tail = newNode;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> a;

        for(auto& it: lists) {
            ListNode* temp = it;
            while(temp) {
                a.push_back(temp->val);
                temp = temp->next;
            }
        }
        std::sort(a.begin(), a.end());

        // for(auto& it: a) {
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        ListNode* head = NULL;
        ListNode* tail = NULL;
        for(auto& it: a) {
            add(it, head, tail);
        }

        return head;
    }
};