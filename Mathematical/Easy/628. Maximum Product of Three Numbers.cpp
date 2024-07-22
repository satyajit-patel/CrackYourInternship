class Solution {
public:
    // n <= 1e4 => O(n^2)
    int maximumProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        // common sence
        return std::max(nums[n-1]*nums[n-2]*nums[n-3], nums[n-1]*nums[0]*nums[1]);
    }
};