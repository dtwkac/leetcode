class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv(numRows);
        for (int i = 0; i < numRows; ++i) {
            vector<int> v(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                v[j] = vv[i - 1][j - 1] + vv[i - 1][j];
            }
            vv[i] = v;
        }
        return vv;
    }
};
