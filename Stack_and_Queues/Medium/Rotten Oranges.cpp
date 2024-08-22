// https://www.geeksforgeeks.org/problems/rotten-oranges2536/1
class Sol {
public:
  int dx[4] = {-1, 0, +1, 0};
  int dy[4] = {0, -1, 0, +1};
  bool isValid(int ni, int nj, vector<vector<int>>& grid) {
    return (ni >= 0 && ni <grid.size() && nj >= 0 && nj < grid[0].size());
  }
  int orangesRotting(vector<vector<int>>& grid) {
    int ans = 0;
    int rot = 0;
    int tot = 0;
    queue<pair<pair<int, int>, int>> q;
    for(int i=0; i<grid.size(); i++) {
      for(int j=0; j<grid[0].size(); j++) {
        if(grid[i][j] != 0) tot++;
        if(grid[i][j] == 2) q.push({{i, j}, 0});
      }
    }
    while(!q.empty()) {
      int i = q.front().first.first;
      int j = q.front().first.second;
      int t = q.front().second;
      q.pop();
      ans = std::max(ans, t);
      rot++;
      for(int ind=0; ind<4; ind++) {
        int ni = i + dx[ind];
        int nj = j + dy[ind];
        if(isValid(ni, nj, grid) && grid[ni][nj] == 1) {
          grid[ni][nj] = 2;
          q.push({{ni, nj}, t+1});
        }
      }
    }
    if(rot == tot) return ans;
    return -1;
  }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        Sol* sol = new Sol();
        return sol->orangesRotting(grid);
    }
};
