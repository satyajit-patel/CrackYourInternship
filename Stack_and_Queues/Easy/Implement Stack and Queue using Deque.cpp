#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

// *****************************************************************

deque<int> dq;
struct MIX {
	MIX() { // constructor
		dq.clear();
		for(int i=1; i<=3; i++) {
			dq.push_back(i);
		}
	}

	void push(int x) {
		dq.push_back(x);
	}

	void enqueue(int x) {
		dq.push_back(x);
	}

	void pop() {
		dq.pop_back();
	}

	void dequeue() {
		dq.pop_front();
	}

	int size() {
		return (int)dq.size();
	}

	bool isempty() {
		return dq.empty();
	}

	void print() {
		for(auto& it: dq) {
			cout<<it<<" ";
		}
		cout<<endl;
	}
};

void solve() {
	/*
	https://www.geeksforgeeks.org/implement-stack-queue-using-deque/
	example 1
		Input : Stack : 1 2 3
        Push(4)
		Output : Stack : 1 2 3 4

		Input : Stack : 1 2 3
		Pop()
		Output : Stack : 1 2

	example 2
		Input: Queue : 1 2 3
       	Enqueue(4)
		Output: Queue : 1 2 3 4

		Input: Queue : 1 2 3
		Dequeue()
		Output: Queue : 2 3
	*/

	MIX* m1 = new MIX();
	m1->push(4);
   	m1->print();
	cout<<endl;

	MIX* m2 = new MIX();
	m2->pop();
   	m2->print();
	cout<<endl;

	MIX* m3 = new MIX();
	m3->enqueue(4);
   	m3->print();
	cout<<endl;

	MIX* m4 = new MIX();
	m4->dequeue();
   	m4->print();
	cout<<endl;
}

// *****************************************************************

int main() {
	solve();
	return 0;
}