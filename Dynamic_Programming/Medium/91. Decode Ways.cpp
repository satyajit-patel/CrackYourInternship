class Solution {
public:
    string str;
    int n;
    vector<int> dp;

    int state(int i) {
        // base case
        if(i >= n) {
            return 1;
        }
        if(str[i] == '0') {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        // transition
        int takeOneDigit = state(i+1);
        int takeTwoDigit = 0;
        if(i+1 < n) {
            // we can take num only which are <= 26
            if(str[i]=='1' || (str[i]=='2'&& str[i+1]<='6')) {
                takeTwoDigit = state(i+2);
            }
        }
        int ans = takeOneDigit + takeTwoDigit;
        dp[i] = ans;
        return ans;
    }

    int numDecodings(string s) {
        n = s.size();
        str = s;
        dp.resize(n+1, -1);
        int ans = state(0);
        return ans;
    }
};