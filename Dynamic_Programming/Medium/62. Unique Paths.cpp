class Solution {
public:
    vector<vector<int>> dp;
    int N, M;

    int state(int i, int j) {
        // base case
        if(i == N-1 && j == M-1) {
            return 1;
        }
        if(i >= N || j >= M) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // transition
        int bottom = state(i+1, j);
        int right = state(i, j+1);
        int ans = bottom + right;
        dp[i][j] = ans;
        return ans;
    }

    int uniquePaths(int m, int n) {
        N = n;
        M = m;
        dp.resize(n+1, vector<int>(m+1, -1));
        int ans = state(0, 0);
        return ans;
    }
};