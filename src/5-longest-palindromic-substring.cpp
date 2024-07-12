class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size(), start = 0, max = 1;
        for (int i = 0; i < size; ++i) {
            int odd_low = i - 1, odd_high = i + 1;
            while (odd_low > -1 && odd_high < size &&
                   s[odd_low] == s[odd_high]) {
                int length = odd_high - odd_low + 1;
                if (length > max) {
                    max = length;
                    start = odd_low;
                }
                --odd_low;
                ++odd_high;
            }
            int even_low = i, even_high = i + 1;
            while (even_low > -1 && even_high < size &&
                   s[even_low] == s[even_high]) {
                int length = even_high - even_low + 1;
                if (length > max) {
                    max = length;
                    start = even_low;
                }
                --even_low;
                ++even_high;
            }
        }
        return s.substr(start, max);
    }
};
