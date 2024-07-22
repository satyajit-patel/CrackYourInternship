class Solution {
public:
    vector<int> dp;
    int state(int i, int n) {
        // base case
        if(i == n) {
            return 1;
        }
        if(i > n) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        // transition
        int ans = 0;
        for(int step=1; step<=2; step++) {
            ans += state(i + step, n);
        }
        return dp[i] = ans;
    }

    int climbStairs(int n) {
        dp.resize(n+1, -1);
        int ans = state(0, n);
        return ans;
    }
};