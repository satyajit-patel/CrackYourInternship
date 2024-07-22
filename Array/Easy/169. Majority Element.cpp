class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int barrier = n / 2;

        map<int, int> mp;
        for(auto& it: nums) {
            mp[it]++;
        }

        for(auto& it: mp) {
            if(it.second > barrier) {
                return it.first;
            }
        }

        return -1;
    }
};