// https://www.geeksforgeeks.org/linked-list-in-zig-zag-fashion/


/*
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
public:
    void zigZagList(Node*& head) { 
    	bool flag = true; 
    	Node* current = head; 
    	while (current->next != NULL) { 
    		if (flag) { 
    			if (current->data > current->next->data) 
    				swap(current->data, current->next->data); 
    		} 
    		else { 
    			if (current->data < current->next->data) 
    				swap(current->data, current->next->data); 
    		} 
    		current = current->next; 
    		flag = !flag; /* flip flag for reverse checking */
    	} 
    } 

    Node* zigZag(Node* head) {
        zigZagList(head);
        return head;
    }
};