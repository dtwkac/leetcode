class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n), right_max(n);
        for (int i = 0; i < n; ++i) {
            left_max[i] = i == 0 ? height[0] : max(left_max[i - 1], height[i]);
        }
        for (int i = n - 1; i > -1; --i) {
            right_max[i] =
                i == n - 1 ? height[i] : max(right_max[i + 1], height[i]);
        }
        int vol = 0;
        for (int i = 0; i < n; ++i) {
            vol += (min(left_max[i], right_max[i]) - height[i]);
        }
        return vol;
    }
};
