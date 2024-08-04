class Solution {
public:
    vector<vector<char>> mat;
    string s;
    int n, m;
    int dx[4] = {0, -1, 0, +1}; // LURD
    int dy[4] = {-1, 0, +1, 0}; 

    bool state(int i, int j, int index) {
        // base case
        if(index >= s.size()) {
            return true;
        }
        if(!(i>=0 && i<n && j>=0 && j<m)) {
            return false;
        }
        if(mat[i][j] != s[index]) {
            return false;
        }

        // transition
        int original = mat[i][j];
        mat[i][j] = '$';
        for(int ind=0; ind<4; ind++) {
            int ni = i + dx[ind];
            int nj = j + dy[ind];
            if(state(ni, nj, index+1)) {
                return true;
            }
        }
        mat[i][j] = original;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        mat.clear();
        mat = board;
        s.clear();
        s = word;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(state(i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};