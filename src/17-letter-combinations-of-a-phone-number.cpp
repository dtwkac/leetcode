class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> m{{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                            {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> v;
        string s;
        vector<bool> chosen(digits.size(), false);
        function<void(const string&, int)> dfs = [&dfs, &m, &v, &s,
                                                  &chosen](const string& digits,
                                                           int level) -> void {
            if (s.size() == digits.size()) {
                v.push_back(s);
                return;
            }
            for (int i = level; i < digits.size(); ++i) {
                if (!chosen[i]) {
                    chosen[i] = true;
                    for (char c : m[digits[i]]) {
                        s.push_back(c);
                        dfs(digits, level + 1);
                        s.pop_back();
                    }
                    chosen[i] = false;
                }
            }
        };
        dfs(digits, 0);
        return v;
    }
};
