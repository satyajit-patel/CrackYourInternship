#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

// *****************************************************************

string f(int n, vector<int>& a, vector<int>& b, int k) {
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end(), greater<int>());
	for(int i=0; i<n; i++) {
		if(a[i] + b[i] < k) {
			return "No";
		}
	}

	return "Yes";
}

void solve() {
    /*
		https://www.geeksforgeeks.org/permute-two-arrays-sum-every-pair-greater-equal-k/

		Input : a[] = {2, 1, 3}, 
        b[] = { 7, 8, 9 }, 
        k = 10. 
		Output : Yes
		Permutation  a[] = { 1, 2, 3 } and b[] = { 9, 8, 7 } 
		satisfied the condition a[i] + b[i] >= K.

		Input : a[] = {1, 2, 2, 1}, 
				b[] = { 3, 3, 3, 4 }, 
				k = 5. 
		Output : No
	*/

	int n; cin>>n;
	vector<int> a(n);
	for(auto& it: a) {
		cin>>it;
	}
	vector<int> b(n);
	for(auto& it: b) {
		cin>>it;
	}
	int k; cin>>k;

	cout<<f(n, a, b, k);
}

// *****************************************************************

int main() {
	solve();
	return 0;
}