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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> x, y, ans;
        while(l1) {
            x.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            y.push_back(l2->val);
            l2 = l2->next;
        }
        std::reverse(x.begin(), x.end());
        std::reverse(y.begin(), y.end());
        int i = 0, j = 0, n = x.size(), m = y.size(), carry = 0;
        while(i < n && j < m) {
            int sum = x[i++] + y[j++] + carry;
            int unitDigit = sum % 10;
            ans.push_back(unitDigit);
            carry = sum / 10; 
        }
        while(i < n) {
            int sum = x[i++] + carry;
            int unitDigit = sum % 10;
            ans.push_back(unitDigit);
            carry = sum / 10;
        }
        while(j < m) {
            int sum = y[j++] + carry;
            int unitDigit = sum % 10;
            ans.push_back(unitDigit);
            carry = sum / 10;
        }
        if(carry) {
            ans.push_back(carry);
        }
        std::reverse(ans.begin(), ans.end());
        ListNode* head = NULL;
        ListNode* tail = NULL;
        for(auto& it: ans) {
            add(it, head, tail);
        }
        return head;
    }
};