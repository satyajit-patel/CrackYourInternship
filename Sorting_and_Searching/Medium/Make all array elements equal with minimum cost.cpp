#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

// *****************************************************************

int minCostToMakeElementEqual(int a[], int n) {
    // If there are odd elements, we choose
    // middle element
    int mid;
    if (n % 2 == 1)
        mid = a[n/2];
 
    // If there are even elements, then we choose
    // the average of middle two.
    else
        mid = (a[n/2] +a[(n-2)/2])/2;
 
    // After deciding the final value, find the
    // result.
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += abs(a[i] - mid);
         
    return sum;
}

void solve() {
    /*
        https://www.geeksforgeeks.org/make-array-elements-equal-minimum-cost/
        
        Input  : arr[] = [1, 100, 101]
        Output : 100
        We can change all its values to 100 with minimum cost,
        |1 - 100| + |100 - 100| + |101 - 100| = 100
        Input  : arr[] = [4, 6]
        Output : 2
        We can change all its values to 5 with minimum cost,
        |4 - 5| + |5 - 6| = 2
    */
    int arr[] = {4, 6};
    cout<<minCostToMakeElementEqual(arr, 2);
}

// *****************************************************************

int main() {
    solve();
    return 0;
}
