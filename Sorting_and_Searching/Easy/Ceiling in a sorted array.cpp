#include <algorithm>
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
		https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/
		For example, 
		let the input array be {1, 2, 8, 10, 10, 12, 19}
		For x = 0:    floor doesn't exist in array,  ceil  = 1
		For x = 1:    floor  = 1,  ceil  = 1
		For x = 5:    floor  = 2,  ceil  = 8
		For x = 20:   floor  = 19,  ceil doesn't exist in array
	*/

	int n; cin>>n;
	vector<int> arr(n);
	for(auto& it: arr) {
		cin>>it;
	}
	int ele; cin>>ele;

	auto it  = std::lower_bound(arr.begin(), arr.end(), ele); // >=

	if(it == arr.begin() && *it != ele) {
		cout<<"floor doesn't exist in array, ";
	} else if(it == arr.begin() && *it == ele) {
		cout<<"floor  = "<<*it<<", ";
	} else {
		auto newIt = it;
		newIt--;
		cout<<"floor  = "<<*(newIt)<<", ";
	}

	if(it == arr.end()) {
		cout<<"ceil doesn't exist in array, ";
	} else {
		cout<<"ceil  = "<<*it<<", ";
	}
}

// *****************************************************************

int main() {
	solve();
	return 0;
}