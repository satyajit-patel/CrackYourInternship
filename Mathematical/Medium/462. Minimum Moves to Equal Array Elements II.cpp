class Solution {
public:
    int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int mid = n/2;
        int j = n-1;
        int cost = 0;

        while(i <= mid) {
            cost += (nums[mid] - nums[i++]);
        }
        while(j >= mid) {
            cost += (nums[j--] - nums[mid]);
        }

        return cost;
    }
};