class Solution {
public:
    int n;
    vector<int> a;
    vector<vector<int>> dp;

    int state(int i, int prev) {
        // base case
        if(i >= n) {
            return 0;
        }
        if(dp[i][prev+1] != -1) {
            return dp[i][prev+1];
        }

        // transition
        int take = 0;
        if(prev == -1 || a[prev] < a[i]) {
            take = 1 + state(i+1, i);
        }
        int notTake = state(i+1, prev);
        int ans = std::max(take, notTake);
        dp[i][prev+1] = ans;
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        a.clear();
        a = nums;
        dp.resize(n+1, vector<int>(n+1, -1));
        int ans = state(0, -1);
        return ans;
    }
};