class Solution {
public:
    int myAtoi(string s) {
        int n = 0;
        int size = s.size();
        bool positive = true;
        for (int i = 0; i < size; ++i) {
            if (s[i] == ' ') {
                continue;
            } else if (s[i] == '+') {
                if (i < size - 1 && (s[i + 1] < '0' || s[i + 1] > '9')) {
                    return 0;
                }
            } else if (s[i] == '-') {
                if (i < size - 1 && (s[i + 1] < '0' || s[i + 1] > '9')) {
                    return 0;
                }
                positive = false;
            } else if (s[i] >= '0' && s[i] <= '9') {
                if (n > INT_MAX / 10 ||
                    (n == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
                    return positive ? INT_MAX : INT_MIN;
                }
                n = n * 10 + (s[i] - '0');
                if (i + 1 < size && (s[i + 1] < '0' || s[i + 1] > '9')) {
                    break;
                }
            } else {
                return 0;
            }
        }
        return positive ? n : -n;
    }
};
