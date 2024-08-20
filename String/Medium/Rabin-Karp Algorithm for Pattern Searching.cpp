#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

// *****************************************************************

void solve() {
    /*
        https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

        input:
        "GEEKS FOR GEEKS";
        "GEEK";

        output:
        Pattern found at index 0
        Pattern found at index 10
    */
    string s;
    std::getline(cin, s);
    string pat; cin>>pat;

    int carry = 0;
    while(1) {
        int index = s.find(pat);
        if(index == -1) {
            break;
        }
        int loc = index + carry;
        cout << "Pattern found at index "<<loc<<endl;
        s.erase(index, 1);
        carry += 1;
    }
}

// *****************************************************************

int main() {
    solve();
    return 0;
}
