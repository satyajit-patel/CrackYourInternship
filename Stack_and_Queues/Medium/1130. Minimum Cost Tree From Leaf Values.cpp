class Solution {
public:
    int mctFromLeafValues(vector<int>& A) {
        int ans = 0;

        vector<int> ds = {INT_MAX};
        for(auto& it: A) {
            while(ds.back() <= it) {
                int mid = ds.back();
                ds.pop_back();
                ans += mid * min(ds.back(), it);
            }
            ds.push_back(it);
        }
        for (int i=2; i<ds.size(); ++i) {
            ans += ds[i] * ds[i-1];
        }

        return ans;
    }
};