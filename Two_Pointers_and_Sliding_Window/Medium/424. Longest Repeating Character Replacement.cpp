class Solution {
public:
    /*
        Input: s = "AABABBA", k = 1
        Output: 4
    */

    int f(map<char, int>& mp) {
        int maxFreq = 0;
        for(auto& it: mp) {
            maxFreq = std::max(maxFreq, it.second);
        }
        return maxFreq;
    }

    int characterReplacement(string s, int k) {
        int maxi = 1;
        int n = s.size();
        map<char, int> mp;
        int init = 0;

        for(int i=0; i<n; i++) {
            mp[s[i]]++;
            int maxFreq = f(mp);

            while((i-init+1 - maxFreq) > k) {
                mp[s[init]]--;
                init++;
                maxFreq = f(mp);
            }

            maxi = std::max(maxi, i-init+1);
        }

        return maxi;
    }
};