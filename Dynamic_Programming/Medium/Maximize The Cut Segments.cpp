// https://www.geeksforgeeks.org/problems/cutted-segments1642/1
class Solution {
public:
    int X, Y, Z;
    vector<int> dp;
    
    int state(int n) {
        // base case
        if(n == 0) {
            return 0;
        }
        if(n < 0) {
            return -1e9;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        
        // transition
        return dp[n] = 1 + std::max({state(n-X), state(n-Y), state(n-Z)});
    }

    int maximizeTheCuts(int n, int x, int y, int z) {
        X = x;
        Y = y;
        Z = z;
        dp.resize(n+1, -1);
        
        int ans = state(n);
        if(ans < 0) {
            return 0;
        }
        return ans;
    }
};