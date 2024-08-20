// https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
class Solution {
public:
    int dx[8] = {0, -1, -1, -1, 0, +1, +1, +1};
    int dy[8] = {-1, -1, 0, +1, +1, +1, 0, -1};

    bool isvalid(int ni, int nj, vector<vector<char>>& grid) {
        return ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size();
    }

    void bfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            i = it.first;
            j = it.second;
            for(int ind=0; ind<8; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isvalid(ni, nj, grid) && !vis[ni][nj] && grid[ni][nj]=='1') {
                    vis[ni][nj] = 1;
                    grid[ni][nj] = 0;
                    q.push({ni, nj});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    bfs(i, j, vis, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
