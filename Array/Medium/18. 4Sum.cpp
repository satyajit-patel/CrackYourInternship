class Solution {
public:
    /*
        1 <= n <= 1e2
        g(n) = O(n^4) tight
    */

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        // f(n) = O(n^3 logn)
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    long long sum = 0LL;
                    sum += nums[i] * 1LL;
                    sum += nums[j] * 1LL;
                    sum += nums[k] * 1LL;
                    // sum + x = target
                    long long x = target - sum;
                    if(std::binary_search(nums.begin()+k+1, nums.end(), x)) {
                        ans.push_back({nums[i], nums[j], nums[k], (int)x});
                        while(k+1 < n && nums[k+1] == nums[k]) {
                            k++;
                        }
                    }
                }
                while(j+1 < n && nums[j+1] == nums[j]) {
                    j++;
                }
            }
            while(i+1 < n && nums[i+1] == nums[i]) {
                i++;
            }
        }

        return ans;
    }
};