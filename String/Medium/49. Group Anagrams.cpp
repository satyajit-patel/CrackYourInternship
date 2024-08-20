class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        int n = strs.size();
        vector<vector<string>> ans;

        for(int i=0; i<n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(strs[i]);
        }
        for(auto& it: mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};