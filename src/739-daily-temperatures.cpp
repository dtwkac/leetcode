class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> v(temperatures.size());
        stack<pair<int, int>> s;
        for (int i = v.size() - 1; i > -1; --i) {
            while (!s.empty() && temperatures[i] >= s.top().second) {
                s.pop();
            }
            v[i] = s.empty() ? 0 : s.top().first - i;
            s.push({i, temperatures[i]});
        }
        return v;
    }
};
