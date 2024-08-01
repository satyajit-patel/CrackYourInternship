// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// backtracking can't be done in bfs
                // dfs
class Solution {
public:
    int dx[4] = {0, -1, 0, 1}; // LURD
    int dy[4] = {-1, 0, 1, 0};
    string dir = "LURD";

    bool isvalid(int i, int j, int n) {
        return i>=0 && i<n && j>=0 && j<n;
    }

    vector<string> ans;
    vector<vector<int>> grid;
    void backtrack(int i, int j, int n, string path) {
        // base case
        if(!isvalid(i, j, n)) {
            return;
        }
        if(grid[i][j] != 1) {
            return;
        }
        if (i == n-1 && j == n-1) {
            ans.push_back(path);
            return;
        }

        // transition
        int original = grid[i][j];
        grid[i][j] = -1;
        for (int ind=0; ind<4; ind++) {
            int ni = i + dx[ind];
            int nj = j + dy[ind];
            backtrack(ni, nj, n, path+dir[ind]);
        }
        grid[i][j] = original; // backtrack
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        ans.clear();
        int n = mat.size();
        grid = mat;

        backtrack(0, 0, n, "");
        
        return ans;
    }
};
