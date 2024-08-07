class Solution {
public:
    vector<double> f(vector<int>& nums) {
        vector<double> ans;
        double mul = 1;
        for(auto& it: nums) {
            mul *= it;
            ans.push_back(mul);
            if(mul == 0) { // edge case
                mul = 1;
            }
        }
        return ans;
    }

    int maxProduct(vector<int>& nums) {
        // anything which remember the past is DP
        vector<double> prefix = f(nums);
        std::reverse(nums.begin(), nums.end());
        vector<double> suffix = f(nums);

        double maxi = -1e9;
        for(int i=0; i<nums.size(); i++) {
            maxi = std::max({maxi, prefix[i], suffix[i]});
        }
        return maxi;
    }
};