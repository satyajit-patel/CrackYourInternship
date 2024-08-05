// https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/0
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> a;
    int N;
    set<vector<int>> st;

    void state(int i) {
        // base case
        if(i >= N) {
            st.insert(a);
            return;
        }
        
        // transition
        for(int j=i; j<N; j++) {
            std::swap(a[i], a[j]);
            state(i+1);
            std::swap(a[i], a[j]);
        }
    }
  
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        ans.clear();
        a.clear();
        a = arr;
        N = n;
        st.clear();
        
        // std::sort(arr.begin(), arr.end());
        // do {
        //     ans.push_back(arr);
        // } while(std::next_permutation(arr.begin(), arr.end()));
        
        state(0);
        for(auto& it: st) {
            ans.push_back(it);
        }
        
        return ans;
    }
};