class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        if (nums.size() == 3) {
            return max(nums[0] + nums[2], nums[1]);
        }
        int i_3 = nums[0], i_2 = max(nums[0], nums[1]),
            i_1 = max(nums[0] + nums[2], nums[1]);
        for (int i = 3; i < nums.size(); ++i) {
            int val = max(i_1, max(i_3, i_2) + nums[i]);
            i_3 = i_2;
            i_2 = i_1;
            i_1 = val;
        }
        return i_1;
    }
};
