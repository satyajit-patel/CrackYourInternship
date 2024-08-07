class Solution {
public:
    vector<int> a;
    vector<vector<int>> dp;
    int n;

    int state(int i, int w) {
        // base case
        if(w == 0) {
            return 0;
        }
        if(w < 0) {
            return 1e9;
        }
        if(i >= n) {
            return 1e9;
        }
        if(dp[i][w] != -1) {
            return dp[i][w];
        }

        // transition
        int take = 1 + state(i, w-a[i]);
        int notTake = state(i+1, w);
        int ans = std::min(take, notTake);
        dp[i][w] = ans;
        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        a.clear();
        a = coins;
        n = a.size();
        dp.resize(n+1, vector<int>(amount+1, -1));
        int ans = state(0, amount);
        if(ans >= 1e9) {
            return -1;
        }
        return ans;
    }
};