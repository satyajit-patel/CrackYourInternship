#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

// *****************************************************************

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

ListNode* head;
ListNode* tail;

void newAdd(int val, ListNode*& newHead, ListNode*& newTail) {
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

struct LL {
	void add(int val) {
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

	void print() {
		ListNode* temp = head;
		while(temp) {
			cout<<temp->val<<" -> ";
			temp = temp->next;
		}
		cout<<"NULL\n";
	}

	void sort() {
		vector<int> v;
		ListNode* temp = head;
		while(temp) {
			v.push_back(temp->val);
			temp = temp->next;
		}

		std::sort(v.begin(), v.end());

		ListNode* newHead = NULL;
		ListNode* newTail = NULL;
		for(auto& it: v) {
			newAdd(it, newHead, newTail);
		}
		head = newHead;
	}
};

void solve() {
    /*
		https://www.geeksforgeeks.org/sort-a-linked-list-of-0s-1s-or-2s/
		Input: 1 -> 1 -> 2 -> 0 -> 2 -> 0 -> 1 -> NULL 
		Output: 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2 -> NULL

		Input: 1 -> 1 -> 2 -> 1 -> 0 -> NULL 
		Output: 0 -> 1 -> 1 -> 1 -> 2 -> NULL 
	*/

	head = NULL;
	tail = NULL;
	LL* ll = new LL();

	int n; cin>>n;
	while(n--) {
		int x; cin>>x;
		ll->add(x);
	}

	cout<<"before-sort: ";
	ll->print();
	ll->sort();
	cout<<"after--sort: ";
	ll->print();
}

// *****************************************************************

int main() {
	solve();
	return 0;
}