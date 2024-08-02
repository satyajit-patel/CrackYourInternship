class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int init = 0;

        /*
            [2,0,2,1,1,0], i=0, init=0, j=5

            [0,0,2,1,1,2], i=0, init=0, j=4
            [0,0,2,1,1,2], i=1, init=1, j=4
            [0,0,2,1,1,2], i=2, init=2, j=4
            [0,0,1,1,2,2], i=2, init=2, j=3
            [0,0,1,1,2,2], i=3, init=2, j=3 
        */

        while(i <= j) {
            if(nums[i] == 0) {
                swap(nums[i], nums[init]);
                i++;
                init++;
            } else if(nums[i] == 2) {
                swap(nums[i], nums[j]);
                j--;
            } else {
                i++;
            }
        }
    }
};