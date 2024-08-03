class Solution {
public:
    vector<int> a;
    vector<vector<int>> dp;
    int n;
    int state(int i, int canBuy) {
        // base case
        if(i >= n) {
            return 0;
        }
        if(dp[i][canBuy] != -1) {
            return dp[i][canBuy];
        }

        // transaction
        int maxi = -1e9;
        if(canBuy) {
            int buy = -a[i] + state(i+1, 0); // can't buy next untill we sell
            int notBuy = state(i+1, 1);
            maxi = std::max({maxi, buy, notBuy});
        } else {
            int sell = a[i] + state(i+1, 1);
            int notSell = state(i+1, 0); // can't buy next untill we sell
            maxi = std::max({maxi, sell, notSell}); 
        }
        dp[i][canBuy] = maxi;
        return maxi;
    }

    int maxProfit(vector<int>& prices) {
        a.clear();
        a = prices;
        n = a.size();
        dp.resize(n+1, vector<int>(2+1, -1));
        int ans = state(0, 1);
        return ans;
    }
};