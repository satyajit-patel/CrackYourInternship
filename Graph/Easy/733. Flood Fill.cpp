class Solution {
public:
    int dx[4] = {0, -1, 0, +1}; // LURD
    int dy[4] = {-1, 0, +1, 0};

    bool isvalid(int i, int j, vector<vector<int>>& grid) {
        return i>=0 && i<grid.size() && j>=0 && j<grid[0].size();
    }

    void bfs(vector<vector<int>>& grid, int i, int j, int newCol, int prevCol) {
        grid[i][j] = newCol;
        queue<pair<int, int>> q;
        q.push({i, j});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            i = it.first;
            j = it.second;

            for(int ind=0; ind<4; ind++) {
                int ni = i + dx[ind];
                int nj = j + dy[ind];
                if(isvalid(ni, nj, grid) && grid[ni][nj] == prevCol) {
                    grid[ni][nj] = newCol;
                    q.push({ni, nj});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) { // edge case
            return image;
        }
        bfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};