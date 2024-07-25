class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v_1;
        for (int i = 0; i <= rowIndex; ++i) {
            vector<int> v(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                v[j] = v_1[j - 1] + v_1[j];
            }
            v_1 = v;
        }
        return v_1;
    }
};
