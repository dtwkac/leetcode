class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, vol = 0, max = 0;
        while (i < j) {
            if (height[i] < height[j]) {
                vol = height[i] * (j - i);
                ++i;
            } else {
                vol = height[j] * (j - i);
                --j;
            }
            max = vol > max ? vol : max;
        }
        return max;
    }
};
