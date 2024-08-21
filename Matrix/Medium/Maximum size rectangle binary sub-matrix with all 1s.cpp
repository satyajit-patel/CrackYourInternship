#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

// *****************************************************************

// https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
class Solution {
public:
    vector<int> getPse(vector<int>& height) {
        int n = height.size();
        vector<int> ans(n, -1);

        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && height[i] <= height[st.top()]) {
                st.pop();
            }

            if(!st.empty()) {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> getNse(vector<int>& height) {
        int n = height.size();
        vector<int> ans(n, -1);

        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && height[i] <= height[st.top()]) {
                st.pop();
            }

            if(!st.empty()) {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    int getMaxAreaOfHistogram(vector<int>& height) {
        int ans = INT_MIN;
        int n = height.size();

        vector<int> pse = getPse(height);
        vector<int> nse = getNse(height);
        for(int i=0; i<n; i++) {
            if(nse[i] == -1) {
                nse[i] = n;
            }
            int curArea = height[i] * (nse[i] - pse[i] - 1);
            ans = max(ans, curArea);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = INT_MIN;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1') {
                    height[j] = height[j] + 1;
                } else {
                    height[j] = 0;
                }
            }
            int curArea = getMaxAreaOfHistogram(height);
            ans = max(ans, curArea);
        }

        return ans;
    }
};

void solve() {
    Solution* sol = new Solution();
    vector<vector<char>> matrix = {
        {'0','1','1','0'},
        {'1','1','1','1'},
        {'1','1','1','1'},
        {'1','1','0','0'}
    };
    cout<<sol->maximalRectangle(matrix);
}

// *****************************************************************

int main() {
    solve();
    return 0;
}
