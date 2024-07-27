class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, left_max = 0, right_max = 0;
        int vol = 0;
        while (left < right) {
            left_max = max(height[left], left_max);
            right_max = max(height[right], right_max);
            if (left_max < right_max) {
                vol += left_max - height[left];
                ++left;
            } else {
                vol += right_max - height[right];
                --right;
            }
        }
        return vol;
    }
};
