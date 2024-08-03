class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        map<int, int> map;
        for(auto& it: nums) {
            map[it]++;
        }
        for(auto& it: map) {
            if(it.second > 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};