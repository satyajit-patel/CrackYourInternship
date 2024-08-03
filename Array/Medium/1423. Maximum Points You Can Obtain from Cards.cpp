class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans = 0;

        int sum = 0;
        for(int i=0; i<k; i++) {
            sum += cardPoints[i];
        }

        ans = std::max(ans, sum);

        int j = n-1;
        for(int i=k-1; i>=0; i--) {
            sum -= cardPoints[i];
            sum += cardPoints[j];
            j--;
            ans = std::max(ans, sum);
        }

        return ans;
    }
};