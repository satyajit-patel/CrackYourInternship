class Solution {
public:
    int f(int ele) {
        int ans = 0;
        for(int bit=0; bit<32; bit++) {
            if(ele & (1 << bit)) { // check iTh bit is set or not
                ans++;
            }
        }
        return ans;
    }

    // n <= 1e5 => O(nlogn)

    vector<int> countBits(int n) {
        vector<int> ans;
        // O(n) * 32 = O(n)
        for(int ele=0; ele<=n; ele++) {
            ans.push_back(f(ele));
        }
        return ans;
    }
};