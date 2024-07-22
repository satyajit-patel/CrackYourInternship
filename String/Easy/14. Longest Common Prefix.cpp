class Solution {
public:
    bool ispresentInAll(int i, vector<string>& strs) {
        char ch = strs[0][i];
        for(auto& row: strs) {
            if(row[i] != ch) {
                return false;
            }
        }

        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int minSize = INT_MAX;
        for(auto& row: strs) {
            int curSize = row.size();
            minSize = std::min(minSize, curSize);
        }

        string ans = "";
        for(int i=0; i<minSize; i++) {
            if(ispresentInAll(i, strs)) {
                ans += strs[0][i];
            } else {
                break;
            }
        }

        return ans;
    }
};