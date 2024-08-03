class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxi = -1e9;

        while(i < j) {
            int l = std::min(height[i], height[j]);
            int b = j - i;
            maxi = std::max(maxi, l * b);

            if(height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxi;
    }
};