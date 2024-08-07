class Solution {
public:
    int m = 1000000007;
    vector<int> adj[10];
    vector<vector<int>> dp;

    int state(int n, int cell) {
        // base case
        if(n == 0) {
            return 1;
        }
        if(dp[n][cell] != -1) {
            return dp[n][cell];
        }

        // transition
        int ans = 0;
        for(auto& child: adj[cell]) {
            ans += state(n-1, child);
            ans %= m;
        }
        return dp[n][cell] = ans;
    }

    int knightDialer(int n) {
        int ans = 0;
        adj[0] = {4, 6};
        adj[1] = {6, 8};
        adj[2] = {7, 9};
        adj[3] = {4, 8};
        adj[4] = {0, 3, 9};
        adj[6] = {0, 1, 7};
        adj[7] = {2, 6};
        adj[8] = {1, 3};
        adj[9] = {2, 4};
        dp.resize(n+1, vector<int>(10+1, -1));

        /*
            O(3^n * 10) i.e. exponential in recursion
            O(n * 10) i.e linear in memoization
        */
        for(int cell=0; cell<10; cell++) {
            ans += state(n-1, cell);
            ans %= m;
        }

        return ans;
    }
};