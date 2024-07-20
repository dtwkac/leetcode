class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0, sum = 0;
        for (int i = digits.size() - 1; i > -1; --i) {
            int add = i == digits.size() - 1 ? 1 : 0;
            sum = (digits[i] + add + carry) % 10;
            carry = (digits[i] + add + carry) / 10;
            digits[i] = sum;
        }
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
