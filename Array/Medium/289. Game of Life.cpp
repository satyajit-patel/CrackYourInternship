class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        int dx[8] = {0, -1, -1, -1, 0, +1, +1, +1}; // LURD
        int dy[8] = {-1, -1, 0, +1, +1, +1, 0, -1};

        vector<vector<int>> mat = board;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int live = 0;
                for(int ind=0; ind<8; ind++) {
                    int ni = i + dx[ind];
                    int nj = j + dy[ind];
                    if(ni>=0 && ni<n && nj>=0 && nj<m) {
                        live += board[ni][nj] == 1;   
                    }
                }
                // cout<<live<<"->";
                if(mat[i][j] == 1) {
                    if(live < 2 || live > 3) {
                        mat[i][j] = 0;
                    }
                } else {
                    if(live == 3) {
                        mat[i][j] = 1;
                    }
                }
            }
            // cout<<endl;
        }

        board = mat;
    }
};