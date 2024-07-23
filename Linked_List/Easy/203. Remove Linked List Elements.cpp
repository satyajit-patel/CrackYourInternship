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

    ListNode* removeElements(ListNode* head, int val) {
        vector<int> v;
        while(head) {
            if(head->val != val) {
                v.push_back(head->val);
            }
            head = head->next;
        }

        ListNode* tail = NULL;
        for(auto& it: v) {
            add(it, head, tail);
        }

        return head;
    }
};