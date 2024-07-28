class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;
        s.push({-1, INT_MAX});
        vector<int> v(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            while (temperatures[i] > s.top().second) {
                v[s.top().first] = i - s.top().first;
                s.pop();
            }
            s.push({i, temperatures[i]});
        }
        return v;
    }
};
