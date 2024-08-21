// https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1
class Solution{
public:
    int missingNumber(int arr[], int n) { 
        set<int> st;
        for(int i=0; i<n; i++) {
            if(arr[i] > 0) {
                st.insert(arr[i]);
            }
        }
        
        for(int ele=1; ele<=1e6; ele++) {
            if(!st.count(ele)) {
                return ele;
            }
        }
        return *std::max_element(arr, arr+n) + 1;
    } 
};