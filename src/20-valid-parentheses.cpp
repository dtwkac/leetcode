class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m{{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> stk;
        for (char c : s) {
            if (m.find(c) == m.end()) {
                stk.push(c);
            } else {
                if (stk.empty() || stk.top() != m[c]) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
