class Solution {
public:
    vector<int> a, dp;

    bool state(int i) {
        // base case
        if(i >= a.size()-1) {
            return true;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        // transition
        for(int step=1; step<=a[i]; step++) {
            if(state(i+step)) {
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
        a.clear();
        a = nums;
        dp.resize(a.size()+1, -1);
        int ans = state(0);
        return ans;
    }
};