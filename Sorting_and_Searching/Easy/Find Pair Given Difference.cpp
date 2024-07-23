https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1
class Solution {
public:
    int findPair(int n, int x, vector<int> &arr) {
        // // O(n^2)
        // for(int i=0; i<n; i++) {
        //     for(int j=i+1; j<n; j++) {
        //         if(std::abs(arr[i] - arr[j]) == x) {
        //             return 1;
        //         }
        //     }
        // }
        
        // O(nlogn)
        std::sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++) {
            // z - a[i] = x
            // z = x + a[i]
            int z = x + arr[i];
            if(std::binary_search(arr.begin()+i+1, arr.end(), z)) {
                return 1;
            }
        }
        
        return -1;
    }
};