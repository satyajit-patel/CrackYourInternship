#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

// *****************************************************************

bool sortArr(int a[], int n) { 
    int l = -1; 
    int r = -1; 
  
    for (int i = 0; i <n-1; i++) { 
        if (a[i] > a[i + 1]) { 
            if(l == -1) { 
                l = i; 
            } 
            r = i + 1; 
        } 
    } 
  
    if (l != -1) { 
        reverse(a+l, a+r+1); 
        for(int i=0; i<n-1; i++) { 
            if (a[i] > a[i+1]) { 
                return false;
            } 
        } 
    } 
    return true; 
} 

void solve() {
    /*
        https://www.geeksforgeeks.org/check-reversing-sub-array-make-array-sorted/
        Input : arr [] = {1, 2, 5, 4, 3}
        Output : Yes
        By reversing the subarray {5, 4, 3}, 
        the array will be sorted.

        Input : arr [] = { 1, 2, 4, 5, 3 }
        Output : No
    */
    int arr[] = {1, 2, 5, 4, 3};
    cout<<sortArr(arr, 5);
}

// *****************************************************************

int main() {
    solve();
    return 0;
}
