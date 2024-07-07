class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        unordered_map<int, int> m;
        vector<int> answer(temperatures.size());
        for (int i = temperatures.size() - 1; i > -1; --i) {
            while (!s.empty() && temperatures[i] >= s.top()) {
                s.pop();
            }
            answer[i] = s.empty() ? 0 : m[s.top()] - i;
            m[temperatures[i]] = i;
            s.push(temperatures[i]);
        }
        return answer;
    }
};
