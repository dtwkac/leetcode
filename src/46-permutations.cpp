class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = 1;
        for (int i = 1; i <= nums.size(); ++i) {
            n *= i;
        }
        auto nextPermutation = [](vector<int>& v) -> bool {
            int i = v.size() - 2;
            while (i > -1 && v[i] >= v[i + 1]) {
                --i;
            }
            if (i < 0) {
                reverse(v.begin(), v.end());
                return false;
            }
            int j = v.size() - 1;
            while (j > i && v[i] >= v[j]) {
                --j;
            }
            swap(v[i], v[j]);
            reverse(v.begin() + i + 1, v.end());
            return true;
        };
        vector<vector<int>> vv(n);
        for (int i = 0; i < n; ++i) {
            vv[i] = nums;
            nextPermutation(nums);
        }
        return vv;
    }
};
