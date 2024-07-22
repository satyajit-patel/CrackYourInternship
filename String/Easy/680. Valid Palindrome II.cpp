class Solution {
public:
    bool f(int i, int j, string& s) {
        while(i <= j) {
            if(s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string& s) {
        // n <= 10^5 => f(n) = O(nlogn)

        // map<char, int> mp;
        // for(auto& it: s) {
        //     mp[it]++;
        // }
        // for(auto& it: mp) {
        //     if(it.second % 2) {
        //         s.erase(s.find(it.first), 1); // take away erase concept
        //         break;
        //     }
        // }

        int i = 0;
        int j = s.size() - 1;
        while(i <= j) {
            if(s[i] != s[j]) {
                return f(i+1, j, s) || f(i, j-1, s);
            }
            i++;
            j--;
        }
        return true;
    }
};