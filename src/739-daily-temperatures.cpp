class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> answer(temperatures.size());
        for (int i = temperatures.size() - 1; i > -1; --i) {
            while (!s.empty() && temperatures[i] >= temperatures[s.top()]) {
                s.pop();
            }
            answer[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }
        return answer;
    }
};
