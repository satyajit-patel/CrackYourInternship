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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        multiset<int> ms;
        while(list1) {
            ms.insert(list1->val);
            list1 = list1->next;
        }
        while(list2) {
            ms.insert(list2->val);
            list2 = list2->next;
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;
        for(auto& it: ms) {
            add(it, head, tail);
        }
        return head;
    }
};