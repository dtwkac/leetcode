class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> vv;
        function<void(const vector<int>&, int, int begin)> dfs =
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
                v.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i);
                v.pop_back();
            }
        };
        dfs(candidates, target, 0);
        return vv;
    }
};
