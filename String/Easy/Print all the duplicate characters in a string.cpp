#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

// *****************************************************************

void solve() {
    /*
		https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/
		Input: S = “geeksforgeeks”
		Output:
		e, count = 4
		g, count = 2
		k, count = 2
		s, count = 2

		Explanation: e,g,k,and s are characters
		which are occured in string in more than one times.
	*/
	
	string s; cin>>s;

	map<char, int> mp;
	for(auto& it: s) {
		mp[it]++;
	}

	for(auto& it: mp) {
		if(it.second > 1) {
			cout<<it.first<<", count = "<<it.second<<endl;
		}
	}
}

// *****************************************************************

int main() {
	solve();
	return 0;
}