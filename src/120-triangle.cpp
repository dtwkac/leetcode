class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty()) {
            return 0;
        }
        vector<int> v_1(triangle[0]);
        for (int i = 1; i < triangle.size(); ++i) {
            vector<int> v(i + 1);
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    v[j] = v_1[j] + triangle[i][j];
                } else if (j == triangle[i].size() - 1) {
                    v[j] = v_1[j - 1] + triangle[i][j];
                } else {
                    v[j] = min(v_1[j - 1], v_1[j]) + triangle[i][j];
                }
            }
            v_1 = v;
        }
        return *min_element(v_1.cbegin(), v_1.cend());
    }
};
