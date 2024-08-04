class Solution {
public:
    /*
        Input: matrix = [
            [1,2,3],
            [4,5,6],
            [7,8,9]
        ]
        Output: [1,2,3,6,9,8,7,4,5]
    */

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        int left = 0;
        int up = 0;
        int right = m-1;
        int down = n-1;
        int totEle = n * m;

        while(ans.size() < totEle) {
            // up 1 2 3
            for(int i=left; i<=right && ans.size()<totEle; i++) {
                ans.push_back(matrix[up][i]);
            }
            up++;

            // right 6 9
            for(int i=up; i<=down && ans.size()<totEle; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // down 8 7
            for(int i=right; i>=left && ans.size()<totEle; i--) {
                ans.push_back(matrix[down][i]);
            }
            down--;

            // left 4
            for(int i=down; i>=up && ans.size()<totEle; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }

        return ans;
    }
};