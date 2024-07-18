class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max = INT_MIN;
        for (int i : nums) {
            sum += i;
            max = sum > max ? sum : max;
            sum = sum > 0 ? sum : 0;
        }
        return max;
    }
};
