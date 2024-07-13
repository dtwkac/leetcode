class Solution {
public:
    int mySqrt(int x) {
        long long i = 0;
        while (i * i <= x) {
            if (i * i == x) {
                return i;
            }
            ++i;
        }
        return i - 1;
    }
};
