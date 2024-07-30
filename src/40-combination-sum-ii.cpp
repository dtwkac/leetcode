class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> vv;
        vector<bool> selected(candidates.size(), false);
        function<void(const vector<int>&, int, int)> dfs =
            [&dfs, &v, &vv, &selected](const vector<int>& candidates,
                                       int target, int begin) -> void {
            if (target < 0) {
                return;
            }
            if (target == 0) {
                vv.push_back(v);
                return;
            }
            unordered_set<int> s;
            for (int i = begin; i < candidates.size(); ++i) {
                if (!selected[i] && s.find(candidates[i]) == s.cend()) {
                    selected[i] = true;
                    s.insert(candidates[i]);
                    v.push_back(candidates[i]);
                    dfs(candidates, target - candidates[i], i);
                    v.pop_back();
                    selected[i] = false;
                }
            }
        };
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return vv;
    }
};
