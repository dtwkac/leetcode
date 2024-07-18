class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, length = 0;
        for (int i : nums) {
            length = i ? length + 1 : 0;
            max = length > max ? length : max;
        }
        return max;
    }
};
