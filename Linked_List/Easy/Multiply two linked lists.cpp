/* 
https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
}; */

class solution {
public:
    long long multiplyTwoLists(Node *first, Node *second) {
        int mod = 1e9 + 7;
        long long n1 = 0;
        while(first) {
            n1 = (long long)((n1 * 10) + (first->data)) % mod;
            first = first->next;
        }
        long long n2 = 0;
        while(second) {
            n2 = (long long)((n2 * 10) + (second->data)) % mod;
            second = second->next;
        }
        return (n1 * n2) % mod;
    }
};