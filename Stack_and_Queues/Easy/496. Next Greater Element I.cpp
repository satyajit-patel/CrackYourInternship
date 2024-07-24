class Solution {
public:
    // n <= 1e3 => O(n^2 logn)
    vector<int> getNge(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            // maintain monotonic increasing
            while(!st.empty() && nums[i] >= st.top()) {
                st.pop();
            }

            if(!st.empty()) {
                ans[i] = st.top();
            }

            // st.push(i);
            st.push(nums[i]);
        }

        return ans;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // o(n)
        vector<int> ans;
        vector<int> nge1 = getNge(nums1);
        vector<int> nge2 = getNge(nums2);
        
        map<int, int> mp;
        for(int i=0; i<nums2.size(); i++) {
            mp[nums2[i]] = i;
        }

        // O(n) as we don't have to search
        // as nums1 is subset of nums2 so ele will definately be there
        for(int i=0; i<nums1.size(); i++) {
            int index = mp[nums1[i]];
            ans.push_back(nge2[index]);
        }

        return ans;
    }
};