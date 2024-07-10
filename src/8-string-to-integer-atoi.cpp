class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) {
            return 0;
        }
        int i = 0;
        while (s[i] == ' ') {
            ++i;
        }
        bool positive = true;
        if (s[i] == '-') {
            positive = false;
            ++i;
        } else if (s[i] == '+') {
            ++i;
        }
        while (s[i] == '0') {
            ++i;
        }
        if (s[i] < '0' || s[i] > '9') {
            return 0;
        }
        long long ans = 0;
        for (int j = i; j < s.size() && s[j] >= '0' && s[j] <= '9'; ++j) {
            ans = ans * 10 + s[j] - '0';
            if (ans > INT_MAX) {
                break;
            }
        }
        ans = positive ? ans : -ans;
        if (ans > INT_MAX) {
            return INT_MAX;
        }
        if (ans < INT_MIN) {
            return INT_MIN;
        }
        return ans;
        return 0;
    }
};
