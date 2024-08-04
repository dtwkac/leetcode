class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<vector<int>> vv;
        vector<bool> selected(n + 1, false);
        function<void(int, int, int)> dfs =
            [&dfs, &v, &vv, &selected](int n, int k, int begin) {
                if (v.size() == k) {
                    vv.push_back(v);
                    return;
                }
                for (int i = begin; i <= n; ++i) {
                    if (!selected[i]) {
                        selected[i] = true;
                        v.push_back(i);
                        dfs(n, k, i + 1);
                        v.pop_back();
                        selected[i] = false;
                    }
                }
            };
        dfs(n, k, 1);
        return vv;
    }
};
