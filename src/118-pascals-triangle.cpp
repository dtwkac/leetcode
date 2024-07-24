class Solution {
public:
    int combination(int n, int m) {
        if (m > n / 2) {
            return combination(n, n - m);
        }
        unsigned long long numerator = 1, denominator = 1;
        for (int i = 1; i <= m; ++i) {
            numerator *= (n - i + 1);
            denominator *= i;
        }
        return numerator / denominator;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        for (int n = 0; n < numRows; ++n) {
            vector<int> v(n + 1);
            for (int m = 0; m <= n / 2; ++m) {
                v[m] = v[n - m] = combination(n, m);
            }
            vv.push_back(v);
        }
        return vv;
    }
};
