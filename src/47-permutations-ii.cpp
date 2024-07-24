class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
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
        vector<vector<int>> vv;
        do {
            vv.push_back(nums);
        } while (nextPermutation(nums));
        return vv;
    }
};
