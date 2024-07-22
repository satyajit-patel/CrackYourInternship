// https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1
class Solution {
public:
    vector<long long> productExceptSelf(vector<long long>& nums, int n) {
        vector<long long> ans(n, 1);
        
        if(n == 1) {
            return ans;
        }
        
        vector<long long> left(n), right(n);
        long long mul = 1;
        for(int i=0; i<n; i++) {
            mul *= nums[i];
            left[i] = mul;
        }
        mul = 1;
        for(int i=n-1; i>=0; i--) {
            mul *= nums[i];
            right[i] = mul;
        }
        
        for(int i=0; i<n; i++) {
            if(i == 0) {
                ans[i] = right[i+1];
            } else if(i == n-1) {
                ans[i] = left[i-1];
            } else {
                ans[i] = left[i-1] * right[i+1];
            }
        }
        
        return ans;
    }
};