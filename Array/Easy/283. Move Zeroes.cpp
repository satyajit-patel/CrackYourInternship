class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> zero, nonZero;
        for(auto& it: nums) {
            if(it == 0) {
                zero.push_back(it);
            } else {
                nonZero.push_back(it);
            }
        }
        nums.clear();
        for(auto& it: nonZero) {
            nums.push_back(it);
        } 
        for(auto& it: zero) {
            nums.push_back(it);
        }
    }
};