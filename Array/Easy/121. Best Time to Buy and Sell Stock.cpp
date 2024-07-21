class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto& it: prices) {
            mini = std::min(mini, it);
            maxi = std::max(maxi, it - mini);
        }
        return maxi;
    }
};