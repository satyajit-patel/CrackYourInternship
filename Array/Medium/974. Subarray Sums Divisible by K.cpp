class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        /*
            interesting fact
            n/k = r
            now if we add any dividant of k in n the r will ne same
            so if we get same r i.e. that added amount must be a divident of k
            ex
                12/4 = 0 
                (12 + 8)/4 = 0
                i.e. 8 must have been a divident of 4
        */

        int sum = 0;
        map<int, int> mp;
        mp[sum]++;
        int subarrayCount = 0;
        
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;

            if(rem < 0) {
                rem += k;
            }

            if(mp[rem]) {
                subarrayCount += mp[rem];
            }
            mp[rem]++;
        }

        return subarrayCount;
    }
};