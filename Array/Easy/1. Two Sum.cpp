class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for(int i=0; i<n; i++) {
            arr[i] = {nums[i], i};
        }
        std::sort(arr.begin(), arr.end());

        int i = 0;
        int j = n - 1;
        
        while(i < j) {
            int sum = arr[i].first + arr[j].first;
            if(sum == target) {
                return {arr[i].second, arr[j].second};
            }
            if(sum > target) {
                j--;
            } else {
                i++;
            }
        }

        return {-1, -1};
    }
};