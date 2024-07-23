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
    int bToD(string& s) {
        int ans = 0;
        std::reverse(s.begin(), s.end());

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '1') {
                ans += (1 << i);
            }
        }

        return ans;
    }

    int getDecimalValue(ListNode* head) {
        // int n = 0;
        string s = "";

        while(head) {
            // n = (n * 10) + head->val;
            s += (head->val + '0');
            head = head->next;
        }

        // // bitset<32> b(std::to_string(n));

        // bitset<32> b(s);
        // return b.to_ulong();

                // or

        return bToD(s);
    }
};