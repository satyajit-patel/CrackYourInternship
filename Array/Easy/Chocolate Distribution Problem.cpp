// https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
class Solution {
public:
    long long findMinDiff(vector<long long> a, long long n, long long m) {
        long long mini = INT_MAX;
        
        // becomes sliding window problem
        std::sort(a.begin(), a.end());
        int init = 0;
        for(int i=0; i<n; i++) {
            if(i - init + 1 == m) {
                long long smallNum = a[init];
                long long largeNum = a[i];
                mini = std::min(mini, largeNum - smallNum);
                init++;
            }
        }
        
        return mini;
    }   
};