class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        if (numRows < 1) {
            return vv;
        }
        for (int i = 1; i <= numRows; ++i) {
            vector<int> v(i, 1);
            for (int j = 1; j < i - 1; ++j) {
                v[j] = vv[i - 2][j - 1] + vv[i - 2][j];
            }
            vv.push_back(v);
        }
        return vv;
    }
};
