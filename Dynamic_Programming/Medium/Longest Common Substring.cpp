// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
class Solution {
public:
    string a, b;
    int n, m;
    vector<vector<int>> dp;
    int maxi;
    
    int state(int i, int j) {
        // base case
        if(i >= n || j >= m) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // transition
        int take = 0;
        if(a[i] == b[j]) {
            take = 1 + state(i+1, j+1);
        }
        state(i+1, j);
        state(i, j+1);
        maxi = std::max(maxi, take);
        return dp[i][j] = take;
    }
  
    int longestCommonSubstr(string s1, string s2) {
        a.clear();
        a = s1;
        b.clear();
        b = s2;
        n =a.size();
        m = b.size();
        
        dp.resize(n+1, vector<int>(m+1, -1));
        maxi = 0;
        state(0, 0);
        return maxi;
        
                // or
                
        // int maxi = 0;
        // for(int i=0; i<s1.size(); i++) {
        //     string temp = "";
        //     for(int j=i; j<s1.size(); j++) {
        //         temp += s1[j];
        //         if(s2.find(temp) != -1) {
        //             maxi = std::max(maxi, (int)temp.size());
        //         }
        //     }
        // }
        // return maxi;
    }
};