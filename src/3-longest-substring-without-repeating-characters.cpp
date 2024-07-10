class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cset;
        int i = 0, max = 0;
        for (int j = 0; j < s.size(); ++j) {
            while (cset.find(s[j]) != cset.cend()) {
                cset.erase(s[i++]);
            }
            cset.insert(s[j]);
            int length = j - i + 1;
            max = length > max ? length : max;
        }
        return max;
    }
};
