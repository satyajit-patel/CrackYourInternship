// https://www.geeksforgeeks.org/problems/print-anagrams-together/1
class Solution{
public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        map<string, vector<string>> mp;
        for(auto& it: string_list) {
            string temp = it;
            std::sort(temp.begin(), temp.end());
            mp[temp].push_back(it);
        }
        
        vector<vector<string>> ans;
        for(auto& it: mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};