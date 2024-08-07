class Solution {
public:
    int n, m;
    vector<vector<int>> mat, dp;

    int state(int i, int j) {
        // base case
        if(i == n-1 && j == m-1) {
            return mat[i][j];
        }
        if(i >= n || j >= m) {
            return 1e9;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // transition
        int bottom = mat[i][j] + state(i+1, j);
        int right = mat[i][j] + state(i, j+1);
        int ans = std::min(bottom, right);
        dp[i][j] = ans;
        return ans;
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        mat.clear();
        mat = grid;
        dp.resize(n+1, vector<int>(m+1, -1));
        int ans = state(0, 0);
        return ans;
    }
};