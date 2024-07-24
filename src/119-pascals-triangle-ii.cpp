class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v{1};
        for (int i = 2; i <= rowIndex + 1; ++i) {
            vector<int> curr(i, 1);
            for (int j = 1; j < i - 1; ++j) {
                curr[j] = v[j - 1] + v[j];
            }
            v = curr;
        }
        return v;
    }
};
