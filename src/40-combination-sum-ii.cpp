class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> vv;
        function<void(const vector<int>&, int, int)> dfs =
            [&dfs, &v, &vv](const vector<int>& candidates, int target,
                            int begin) -> void {
            if (target < 0) {
                return;
            }
            if (target == 0) {
                vv.push_back(v);
                return;
            }
            for (int i = begin; i < candidates.size(); ++i) {
                if (i > begin && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                v.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i + 1);
                v.pop_back();
            }
        };
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return vv;
    }
};
